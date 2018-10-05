/*
 * Copyright (C) 2018 Purism SPC
 * SPDX-License-Identifier: GPL-3.0+
 * Author: Guido Günther <agx@sigxcpu.org>
 */
#pragma once

#include "phosh-wayland.h"

#include <glib-object.h>
#include <gdk/gdk.h>


typedef struct _PhoshMonitorMode
{
  gint width, height;
  gint refresh;
  guint32 flags;
} PhoshMonitorMode;


#define PHOSH_TYPE_MONITOR                 (phosh_monitor_get_type ())

struct _PhoshMonitor {
  GObject parent;

  struct wl_output *wl_output;
  struct zxdg_output_v1 *xdg_output;
  gint x, y, width, height;
  gint subpixel;
  gint32 transform, scale;

  gint width_mm;
  gint height_mm;

  char *vendor;
  char *product;

  GArray *modes;
  guint current_mode;
  guint preferred_mode;

  gboolean wl_output_done;
  gboolean xdg_output_done;
};

G_DECLARE_FINAL_TYPE (PhoshMonitor, phosh_monitor, PHOSH, MONITOR, GObject)

PhoshMonitor     * phosh_monitor_new_from_wl_output (gpointer wl_output);
PhoshMonitorMode * phosh_monitor_get_current_mode (PhoshMonitor *monitor);
gboolean           phosh_monitor_is_configured (PhoshMonitor *monitor);
