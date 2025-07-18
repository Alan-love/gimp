/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpimageselect_pdb.h
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

/* NOTE: This file is auto-generated by pdbgen.pl */

#pragma once

#if !defined (__GIMP_H_INSIDE__) && !defined (GIMP_COMPILATION)
#error "Only <libgimp/gimp.h> can be included directly."
#endif

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


gboolean gimp_image_select_color            (GimpImage      *image,
                                             GimpChannelOps  operation,
                                             GimpDrawable   *drawable,
                                             GeglColor      *color);
gboolean gimp_image_select_contiguous_color (GimpImage      *image,
                                             GimpChannelOps  operation,
                                             GimpDrawable   *drawable,
                                             gdouble         x,
                                             gdouble         y);
gboolean gimp_image_select_rectangle        (GimpImage      *image,
                                             GimpChannelOps  operation,
                                             gdouble         x,
                                             gdouble         y,
                                             gdouble         width,
                                             gdouble         height);
gboolean gimp_image_select_round_rectangle  (GimpImage      *image,
                                             GimpChannelOps  operation,
                                             gdouble         x,
                                             gdouble         y,
                                             gdouble         width,
                                             gdouble         height,
                                             gdouble         corner_radius_x,
                                             gdouble         corner_radius_y);
gboolean gimp_image_select_ellipse          (GimpImage      *image,
                                             GimpChannelOps  operation,
                                             gdouble         x,
                                             gdouble         y,
                                             gdouble         width,
                                             gdouble         height);
gboolean gimp_image_select_polygon          (GimpImage      *image,
                                             GimpChannelOps  operation,
                                             gsize           num_segs,
                                             const gdouble  *segs);
gboolean gimp_image_select_item             (GimpImage      *image,
                                             GimpChannelOps  operation,
                                             GimpItem       *item);

G_END_DECLS
