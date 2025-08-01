/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpcolordisplaystack.h
 * Copyright (C) 2003 Michael Natterer <mitch@gimp.org>
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

#pragma once

#if !defined (__GIMP_WIDGETS_H_INSIDE__) && !defined (GIMP_WIDGETS_COMPILATION)
#error "Only <libgimpwidgets/gimpwidgets.h> can be included directly."
#endif

G_BEGIN_DECLS

/* For information look at the html documentation */


#define GIMP_TYPE_COLOR_DISPLAY_STACK (gimp_color_display_stack_get_type ())
G_DECLARE_FINAL_TYPE (GimpColorDisplayStack,
                      gimp_color_display_stack,
                      GIMP, COLOR_DISPLAY_STACK,
                      GObject)


GimpColorDisplayStack * gimp_color_display_stack_new   (void);
GimpColorDisplayStack * gimp_color_display_stack_clone (GimpColorDisplayStack *stack);

void    gimp_color_display_stack_changed         (GimpColorDisplayStack *stack);

GList * gimp_color_display_stack_get_filters     (GimpColorDisplayStack *stack);

void    gimp_color_display_stack_add             (GimpColorDisplayStack *stack,
                                                  GimpColorDisplay      *display);
void    gimp_color_display_stack_remove          (GimpColorDisplayStack *stack,
                                                  GimpColorDisplay      *display);
void    gimp_color_display_stack_reorder_up      (GimpColorDisplayStack *stack,
                                                  GimpColorDisplay      *display);
void    gimp_color_display_stack_reorder_down    (GimpColorDisplayStack *stack,
                                                  GimpColorDisplay      *display);
void    gimp_color_display_stack_convert_buffer  (GimpColorDisplayStack *stack,
                                                  GeglBuffer            *buffer,
                                                  GeglRectangle         *area);

G_END_DECLS
