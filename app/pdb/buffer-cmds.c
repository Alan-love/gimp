/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-2003 Spencer Kimball and Peter Mattis
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

/* NOTE: This file is auto-generated by pdbgen.pl. */

#include "config.h"

#include "stamp-pdbgen.h"

#include <string.h>

#include <gegl.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include "libgimpbase/gimpbase.h"

#include "pdb-types.h"

#include "core/gimp.h"
#include "core/gimpbuffer.h"
#include "core/gimpcontainer-filter.h"
#include "core/gimpcontainer.h"
#include "core/gimpparamspecs.h"
#include "gegl/gimp-babl-compat.h"

#include "gimppdb.h"
#include "gimppdb-utils.h"
#include "gimpprocedure.h"
#include "internal-procs.h"


static GimpValueArray *
buffers_get_name_list_invoker (GimpProcedure         *procedure,
                               Gimp                  *gimp,
                               GimpContext           *context,
                               GimpProgress          *progress,
                               const GimpValueArray  *args,
                               GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  const gchar *filter;
  gchar **buffer_list = NULL;

  filter = g_value_get_string (gimp_value_array_index (args, 0));

  if (success)
    {
      buffer_list = gimp_container_get_filtered_name_array (gimp->named_buffers,
                                                            filter);
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_take_boxed (gimp_value_array_index (return_vals, 1), buffer_list);

  return return_vals;
}

static GimpValueArray *
buffer_rename_invoker (GimpProcedure         *procedure,
                       Gimp                  *gimp,
                       GimpContext           *context,
                       GimpProgress          *progress,
                       const GimpValueArray  *args,
                       GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  const gchar *buffer_name;
  const gchar *new_name;
  gchar *real_name = NULL;

  buffer_name = g_value_get_string (gimp_value_array_index (args, 0));
  new_name = g_value_get_string (gimp_value_array_index (args, 1));

  if (success)
    {
      GimpBuffer *buffer = gimp_pdb_get_buffer (gimp, buffer_name, error);

      if (buffer)
        {
          gimp_object_set_name (GIMP_OBJECT (buffer), new_name);
          real_name = g_strdup (gimp_object_get_name (buffer));
        }
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_take_string (gimp_value_array_index (return_vals, 1), real_name);

  return return_vals;
}

static GimpValueArray *
buffer_delete_invoker (GimpProcedure         *procedure,
                       Gimp                  *gimp,
                       GimpContext           *context,
                       GimpProgress          *progress,
                       const GimpValueArray  *args,
                       GError               **error)
{
  gboolean success = TRUE;
  const gchar *buffer_name;

  buffer_name = g_value_get_string (gimp_value_array_index (args, 0));

  if (success)
    {
      GimpBuffer *buffer = gimp_pdb_get_buffer (gimp, buffer_name, error);

      if (buffer)
        success = gimp_container_remove (gimp->named_buffers, GIMP_OBJECT (buffer));
      else
        success = FALSE;
    }

  return gimp_procedure_get_return_values (procedure, success,
                                           error ? *error : NULL);
}

static GimpValueArray *
buffer_get_width_invoker (GimpProcedure         *procedure,
                          Gimp                  *gimp,
                          GimpContext           *context,
                          GimpProgress          *progress,
                          const GimpValueArray  *args,
                          GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  const gchar *buffer_name;
  gint width = 0;

  buffer_name = g_value_get_string (gimp_value_array_index (args, 0));

  if (success)
    {
      GimpBuffer *buffer = gimp_pdb_get_buffer (gimp, buffer_name, error);

      if (buffer)
        width = gimp_buffer_get_width (buffer);
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_int (gimp_value_array_index (return_vals, 1), width);

  return return_vals;
}

static GimpValueArray *
buffer_get_height_invoker (GimpProcedure         *procedure,
                           Gimp                  *gimp,
                           GimpContext           *context,
                           GimpProgress          *progress,
                           const GimpValueArray  *args,
                           GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  const gchar *buffer_name;
  gint height = 0;

  buffer_name = g_value_get_string (gimp_value_array_index (args, 0));

  if (success)
    {
      GimpBuffer *buffer = gimp_pdb_get_buffer (gimp, buffer_name, error);

      if (buffer)
        height = gimp_buffer_get_height (buffer);
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_int (gimp_value_array_index (return_vals, 1), height);

  return return_vals;
}

static GimpValueArray *
buffer_get_bytes_invoker (GimpProcedure         *procedure,
                          Gimp                  *gimp,
                          GimpContext           *context,
                          GimpProgress          *progress,
                          const GimpValueArray  *args,
                          GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  const gchar *buffer_name;
  gint bytes = 0;

  buffer_name = g_value_get_string (gimp_value_array_index (args, 0));

  if (success)
    {
      GimpBuffer *buffer = gimp_pdb_get_buffer (gimp, buffer_name, error);

      if (buffer)
        {
          const Babl *format = gimp_buffer_get_format (buffer);

          bytes = babl_format_get_bytes_per_pixel (format);
        }
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_int (gimp_value_array_index (return_vals, 1), bytes);

  return return_vals;
}

static GimpValueArray *
buffer_get_image_type_invoker (GimpProcedure         *procedure,
                               Gimp                  *gimp,
                               GimpContext           *context,
                               GimpProgress          *progress,
                               const GimpValueArray  *args,
                               GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  const gchar *buffer_name;
  gint image_type = 0;

  buffer_name = g_value_get_string (gimp_value_array_index (args, 0));

  if (success)
    {
      GimpBuffer *buffer = gimp_pdb_get_buffer (gimp, buffer_name, error);

      if (buffer)
        image_type = gimp_babl_format_get_image_type (gimp_buffer_get_format (buffer));
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_enum (gimp_value_array_index (return_vals, 1), image_type);

  return return_vals;
}

void
register_buffer_procs (GimpPDB *pdb)
{
  GimpProcedure *procedure;

  /*
   * gimp-buffers-get-name-list
   */
  procedure = gimp_procedure_new (buffers_get_name_list_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-buffers-get-name-list");
  gimp_procedure_set_static_help (procedure,
                                  "Retrieve a complete listing of the available buffers.",
                                  "This procedure returns a complete listing of available named buffers.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2005");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("filter",
                                                       "filter",
                                                       "An optional regular expression used to filter the list",
                                                       FALSE, TRUE, FALSE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_boxed ("buffer-list",
                                                       "buffer list",
                                                       "The list of buffer names",
                                                       G_TYPE_STRV,
                                                       GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-buffer-rename
   */
  procedure = gimp_procedure_new (buffer_rename_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-buffer-rename");
  gimp_procedure_set_static_help (procedure,
                                  "Renames a named buffer.",
                                  "This procedure renames a named buffer.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2005");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("buffer-name",
                                                       "buffer name",
                                                       "The buffer name",
                                                       FALSE, FALSE, TRUE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("new-name",
                                                       "new name",
                                                       "The buffer's new name",
                                                       FALSE, FALSE, TRUE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   gimp_param_spec_string ("real-name",
                                                           "real name",
                                                           "The real name given to the buffer",
                                                           FALSE, FALSE, FALSE,
                                                           NULL,
                                                           GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-buffer-delete
   */
  procedure = gimp_procedure_new (buffer_delete_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-buffer-delete");
  gimp_procedure_set_static_help (procedure,
                                  "Deletes a named buffer.",
                                  "This procedure deletes a named buffer.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "David Gowers <neota@softhome.net>",
                                         "David Gowers <neota@softhome.net>",
                                         "2005");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("buffer-name",
                                                       "buffer name",
                                                       "The buffer name",
                                                       FALSE, FALSE, TRUE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-buffer-get-width
   */
  procedure = gimp_procedure_new (buffer_get_width_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-buffer-get-width");
  gimp_procedure_set_static_help (procedure,
                                  "Retrieves the specified buffer's width.",
                                  "This procedure retrieves the specified named buffer's width.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2005");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("buffer-name",
                                                       "buffer name",
                                                       "The buffer name",
                                                       FALSE, FALSE, TRUE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("width",
                                                     "width",
                                                     "The buffer width",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-buffer-get-height
   */
  procedure = gimp_procedure_new (buffer_get_height_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-buffer-get-height");
  gimp_procedure_set_static_help (procedure,
                                  "Retrieves the specified buffer's height.",
                                  "This procedure retrieves the specified named buffer's height.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2005");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("buffer-name",
                                                       "buffer name",
                                                       "The buffer name",
                                                       FALSE, FALSE, TRUE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("height",
                                                     "height",
                                                     "The buffer height",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-buffer-get-bytes
   */
  procedure = gimp_procedure_new (buffer_get_bytes_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-buffer-get-bytes");
  gimp_procedure_set_static_help (procedure,
                                  "Retrieves the specified buffer's bytes.",
                                  "This procedure retrieves the specified named buffer's bytes.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2005");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("buffer-name",
                                                       "buffer name",
                                                       "The buffer name",
                                                       FALSE, FALSE, TRUE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("bytes",
                                                     "bytes",
                                                     "The buffer bpp",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-buffer-get-image-type
   */
  procedure = gimp_procedure_new (buffer_get_image_type_invoker, FALSE);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-buffer-get-image-type");
  gimp_procedure_set_static_help (procedure,
                                  "Retrieves the specified buffer's image type.",
                                  "This procedure retrieves the specified named buffer's image type.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2005");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("buffer-name",
                                                       "buffer name",
                                                       "The buffer name",
                                                       FALSE, FALSE, TRUE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_enum ("image-type",
                                                      "image type",
                                                      "The buffer image type",
                                                      GIMP_TYPE_IMAGE_TYPE,
                                                      GIMP_RGB_IMAGE,
                                                      GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);
}
