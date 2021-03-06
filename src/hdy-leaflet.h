/*
 * Copyright (C) 2018 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#if !defined(_HANDY_INSIDE) && !defined(HANDY_COMPILATION)
#error "Only <handy.h> can be included directly."
#endif

#include <gtk/gtk.h>
#include "hdy-deprecation-macros.h"
#include "hdy-fold.h"
#include "hdy-enums.h"

G_BEGIN_DECLS

#define HDY_TYPE_LEAFLET (hdy_leaflet_get_type())

G_DECLARE_DERIVABLE_TYPE (HdyLeaflet, hdy_leaflet, HDY, LEAFLET, GtkContainer)

typedef enum {
  HDY_LEAFLET_TRANSITION_TYPE_NONE,
  HDY_LEAFLET_TRANSITION_TYPE_SLIDE,
  HDY_LEAFLET_TRANSITION_TYPE_OVER,
  HDY_LEAFLET_TRANSITION_TYPE_UNDER,
} HdyLeafletTransitionType;

_HDY_DEPRECATED_FOR (HdyLeafletTransitionType)
typedef enum {
  HDY_LEAFLET_MODE_TRANSITION_TYPE_NONE,
  HDY_LEAFLET_MODE_TRANSITION_TYPE_SLIDE,
} HdyLeafletModeTransitionType;

_HDY_DEPRECATED_FOR (HdyLeafletTransitionType)
typedef enum {
  HDY_LEAFLET_CHILD_TRANSITION_TYPE_NONE,
  HDY_LEAFLET_CHILD_TRANSITION_TYPE_CROSSFADE,
  HDY_LEAFLET_CHILD_TRANSITION_TYPE_SLIDE,
  HDY_LEAFLET_CHILD_TRANSITION_TYPE_OVER,
  HDY_LEAFLET_CHILD_TRANSITION_TYPE_UNDER,
} HdyLeafletChildTransitionType;

/**
 * HdyLeafletClass
 * @parent_class: The parent class
 */
struct _HdyLeafletClass
{
  GtkContainerClass parent_class;

  /*< private >*/

  /* Signals
   */
  void (*todo) (HdyLeaflet *self);
};

GtkWidget       *hdy_leaflet_new (void);
HdyFold          hdy_leaflet_get_fold (HdyLeaflet *self);
GtkWidget       *hdy_leaflet_get_visible_child (HdyLeaflet *self);
void             hdy_leaflet_set_visible_child (HdyLeaflet *self,
                                                GtkWidget  *visible_child);
const gchar     *hdy_leaflet_get_visible_child_name (HdyLeaflet *self);
void             hdy_leaflet_set_visible_child_name (HdyLeaflet  *self,
                                                     const gchar *name);
gboolean         hdy_leaflet_get_homogeneous (HdyLeaflet     *self,
                                              HdyFold         fold,
                                              GtkOrientation  orientation);
void             hdy_leaflet_set_homogeneous (HdyLeaflet     *self,
                                              HdyFold         fold,
                                              GtkOrientation  orientation,
                                              gboolean        homogeneous);
HdyLeafletTransitionType hdy_leaflet_get_transition_type (HdyLeaflet *self);
void             hdy_leaflet_set_transition_type (HdyLeaflet               *self,
                                                  HdyLeafletTransitionType  transition);

G_GNUC_BEGIN_IGNORE_DEPRECATIONS
_HDY_DEPRECATED_FOR (hdy_leaflet_get_transition_type)
HdyLeafletModeTransitionType hdy_leaflet_get_mode_transition_type (HdyLeaflet *self);
_HDY_DEPRECATED_FOR (hdy_leaflet_set_transition_type)
void             hdy_leaflet_set_mode_transition_type (HdyLeaflet                   *self,
                                                       HdyLeafletModeTransitionType  transition);
G_GNUC_END_IGNORE_DEPRECATIONS

guint            hdy_leaflet_get_mode_transition_duration (HdyLeaflet *self);
void             hdy_leaflet_set_mode_transition_duration (HdyLeaflet *self,
                                                           guint       duration);

G_GNUC_BEGIN_IGNORE_DEPRECATIONS
_HDY_DEPRECATED_FOR (hdy_leaflet_get_transition_type)
HdyLeafletChildTransitionType hdy_leaflet_get_child_transition_type (HdyLeaflet *self);
_HDY_DEPRECATED_FOR (hdy_leaflet_set_transition_type)
void             hdy_leaflet_set_child_transition_type (HdyLeaflet                    *self,
                                                        HdyLeafletChildTransitionType  transition);
G_GNUC_END_IGNORE_DEPRECATIONS

guint            hdy_leaflet_get_child_transition_duration (HdyLeaflet *self);
void             hdy_leaflet_set_child_transition_duration (HdyLeaflet *self,
                                                            guint       duration);
gboolean         hdy_leaflet_get_child_transition_running (HdyLeaflet *self);
gboolean         hdy_leaflet_get_interpolate_size (HdyLeaflet *self);
void             hdy_leaflet_set_interpolate_size (HdyLeaflet *self,
                                                   gboolean    interpolate_size);
gboolean         hdy_leaflet_get_can_swipe_back (HdyLeaflet *self);
void             hdy_leaflet_set_can_swipe_back (HdyLeaflet *self,
                                                 gboolean    can_swipe_back);
gboolean         hdy_leaflet_get_can_swipe_forward (HdyLeaflet *self);
void             hdy_leaflet_set_can_swipe_forward (HdyLeaflet *self,
                                                    gboolean    can_swipe_forward);

G_END_DECLS
