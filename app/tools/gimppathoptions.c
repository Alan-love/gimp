/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * gimppathoptions.c
 * Copyright (C) 1999 Sven Neumann <sven@gimp.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "config.h"

#include <gegl.h>
#include <gtk/gtk.h>

#include "libgimpbase/gimpbase.h"
#include "libgimpconfig/gimpconfig.h"
#include "libgimpwidgets/gimpwidgets.h"

#include "tools-types.h"

#include "widgets/gimphelp-ids.h"
#include "widgets/gimpwidgets-utils.h"

#include "gimppathoptions.h"
#include "gimptooloptions-gui.h"

#include "gimp-intl.h"


enum
{
  PROP_0,
  PROP_PATH_EDIT_MODE,
  PROP_PATH_POLYGONAL
};


static void   gimp_path_options_set_property (GObject      *object,
                                              guint         property_id,
                                              const GValue *value,
                                              GParamSpec   *pspec);
static void   gimp_path_options_get_property (GObject      *object,
                                              guint         property_id,
                                              GValue       *value,
                                              GParamSpec   *pspec);


G_DEFINE_TYPE (GimpPathOptions, gimp_path_options, GIMP_TYPE_TOOL_OPTIONS)


static void
gimp_path_options_class_init (GimpPathOptionsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->set_property = gimp_path_options_set_property;
  object_class->get_property = gimp_path_options_get_property;

  GIMP_CONFIG_PROP_ENUM (object_class, PROP_PATH_EDIT_MODE,
                         "path-edit-mode",
                         _("Edit Mode"),
                         NULL,
                         GIMP_TYPE_PATH_MODE,
                         GIMP_PATH_MODE_DESIGN,
                         GIMP_PARAM_STATIC_STRINGS);

  GIMP_CONFIG_PROP_BOOLEAN (object_class, PROP_PATH_POLYGONAL,
                            "path-polygonal",
                            _("Polygonal"),
                            _("Restrict editing to polygons"),
                            FALSE,
                            GIMP_PARAM_STATIC_STRINGS);
}

static void
gimp_path_options_init (GimpPathOptions *options)
{
}

static void
gimp_path_options_set_property (GObject      *object,
                                guint         property_id,
                                const GValue *value,
                                GParamSpec   *pspec)
{
  GimpPathOptions *options = GIMP_PATH_OPTIONS (object);

  switch (property_id)
    {
    case PROP_PATH_EDIT_MODE:
      options->edit_mode = g_value_get_enum (value);
      break;
    case PROP_PATH_POLYGONAL:
      options->polygonal = g_value_get_boolean (value);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}


static void
gimp_path_options_get_property (GObject    *object,
                                  guint       property_id,
                                  GValue     *value,
                                  GParamSpec *pspec)
{
  GimpPathOptions *options = GIMP_PATH_OPTIONS (object);

  switch (property_id)
    {
    case PROP_PATH_EDIT_MODE:
      g_value_set_enum (value, options->edit_mode);
      break;
    case PROP_PATH_POLYGONAL:
      g_value_set_boolean (value, options->polygonal);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
button_append_modifier (GtkWidget       *button,
                        GdkModifierType  modifiers)
{
  gchar *str = g_strdup_printf ("%s (%s)",
                                gtk_button_get_label (GTK_BUTTON (button)),
                                gimp_get_mod_string (modifiers));

  gtk_button_set_label (GTK_BUTTON (button), str);
  g_free (str);
}

GtkWidget *
gimp_path_options_gui (GimpToolOptions *tool_options)
{
  GObject           *config  = G_OBJECT (tool_options);
  GimpPathOptions *options = GIMP_PATH_OPTIONS (tool_options);
  GtkWidget         *vbox    = gimp_tool_options_gui (tool_options);
  GtkWidget         *frame;
  GtkWidget         *button;
  gchar             *str;

  /*  tool toggle  */
  frame = gimp_prop_enum_radio_frame_new (config, "path-edit-mode", NULL,
                                          0, 0);
  gtk_box_pack_start (GTK_BOX (vbox), frame, FALSE, FALSE, 0);

  button = g_object_get_data (G_OBJECT (frame), "radio-button");

  if (GTK_IS_RADIO_BUTTON (button))
    {
      GSList *list = gtk_radio_button_get_group (GTK_RADIO_BUTTON (button));

      /* GIMP_PATH_MODE_MOVE  */
      button_append_modifier (list->data, GDK_MOD1_MASK);

      if (list->next)   /* GIMP_PATH_MODE_EDIT  */
        button_append_modifier (list->next->data,
                                gimp_get_toggle_behavior_mask ());
    }

  button = gimp_prop_check_button_new (config, "path-polygonal", NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);

  str = g_strdup_printf (_("Path to Selection\n"
                           "%s  Add\n"
                           "%s  Subtract\n"
                           "%s  Intersect"),
                         gimp_get_mod_string (gimp_get_extend_selection_mask ()),
                         gimp_get_mod_string (gimp_get_modify_selection_mask ()),
                         gimp_get_mod_string (gimp_get_extend_selection_mask () |
                                              gimp_get_modify_selection_mask ()));

  button = gimp_button_new ();
  /*  Create a selection from the current path  */
  gtk_button_set_label (GTK_BUTTON (button), _("Selection from Path"));
  gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);
  gtk_widget_set_sensitive (button, FALSE);
  gimp_help_set_help_data (button, str, GIMP_HELP_PATH_SELECTION_REPLACE);
  gtk_widget_show (button);

  g_free (str);

  options->to_selection_button = button;

  button = gtk_button_new_with_label (_("Fill Path"));
  gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);
  gtk_widget_set_sensitive (button, FALSE);
  gimp_help_set_help_data (button, NULL, GIMP_HELP_PATH_FILL);
  gtk_widget_show (button);

  options->fill_button = button;

  button = gtk_button_new_with_label (_("Stroke Path"));
  gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);
  gtk_widget_set_sensitive (button, FALSE);
  gimp_help_set_help_data (button, NULL, GIMP_HELP_PATH_STROKE);
  gtk_widget_show (button);

  options->stroke_button = button;

  return vbox;
}
