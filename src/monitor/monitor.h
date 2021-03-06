/*
 * Copyright (C) 2018 Purism SPC
 * SPDX-License-Identifier: GPL-3.0+
 * Author: Guido Günther <agx@sigxcpu.org>
 */
#pragma once

#include "phosh-enums.h"
#include "phosh-wayland.h"

#include <gdk/gdk.h>
#include <glib-object.h>
#include <glib/gi18n.h>

/* This matches the values in drm_mode.h */
typedef enum _PhoshMonitorConnectorType
{
  PHOSH_MONITOR_CONNECTOR_TYPE_Unknown = 0,
  PHOSH_MONITOR_CONNECTOR_TYPE_VGA = 1,
  PHOSH_MONITOR_CONNECTOR_TYPE_DVII = 2,
  PHOSH_MONITOR_CONNECTOR_TYPE_DVID = 3,
  PHOSH_MONITOR_CONNECTOR_TYPE_DVIA = 4,
  PHOSH_MONITOR_CONNECTOR_TYPE_Composite = 5,
  PHOSH_MONITOR_CONNECTOR_TYPE_SVIDEO = 6,
  PHOSH_MONITOR_CONNECTOR_TYPE_LVDS = 7,
  PHOSH_MONITOR_CONNECTOR_TYPE_Component = 8,
  PHOSH_MONITOR_CONNECTOR_TYPE_9PinDIN = 9,
  PHOSH_MONITOR_CONNECTOR_TYPE_DisplayPort = 10,
  PHOSH_MONITOR_CONNECTOR_TYPE_HDMIA = 11,
  PHOSH_MONITOR_CONNECTOR_TYPE_HDMIB = 12,
  PHOSH_MONITOR_CONNECTOR_TYPE_TV = 13,
  PHOSH_MONITOR_CONNECTOR_TYPE_eDP = 14,
  PHOSH_MONITOR_CONNECTOR_TYPE_VIRTUAL = 15,
  PHOSH_MONITOR_CONNECTOR_TYPE_DSI = 16,
} PhoshMonitorConnectorType;


typedef struct _PhoshMonitorMode
{
  gint width, height;
  gint refresh;
  guint32 flags;
} PhoshMonitorMode;

/**
 * PhoshMonitorPowerSaveMode:
 * @PHOSH_MONITOR_POWER_SAVE_MODE_ON: The monitor is on
 * @PHOSH_MONITOR_POWER_SAVE_MODE_OFF: The monitor is off (saving power)
 *
 * The power save mode of a monitor
 */
typedef enum _PhoshMonitorPowerSaveMode {
  PHOSH_MONITOR_POWER_SAVE_MODE_OFF = 0,
  PHOSH_MONITOR_POWER_SAVE_MODE_ON  = 1,
} PhoshMonitorPowerSaveMode;

#define PHOSH_TYPE_MONITOR                 (phosh_monitor_get_type ())

struct _PhoshMonitor {
  GObject parent;

  struct wl_output *wl_output;
  struct zxdg_output_v1 *xdg_output;
  struct zwlr_output_power_v1 *wlr_output_power;
  PhoshMonitorPowerSaveMode power_mode;

  gint x, y, width, height;
  gint subpixel;
  gint32 transform, scale;

  struct {
    gint32 x, y, width, height;
  } logical;

  gint width_mm;
  gint height_mm;

  gchar *vendor;
  gchar *product;

  GArray *modes;
  guint current_mode;
  guint preferred_mode;

  gchar *name;
  PhoshMonitorConnectorType conn_type;

  gboolean wl_output_done;
  gboolean xdg_output_done;
};

G_DECLARE_FINAL_TYPE (PhoshMonitor, phosh_monitor, PHOSH, MONITOR, GObject)

PhoshMonitor     * phosh_monitor_new_from_wl_output (gpointer wl_output);
PhoshMonitorMode * phosh_monitor_get_current_mode (PhoshMonitor *monitor);
gboolean           phosh_monitor_is_configured (PhoshMonitor *monitor);
gboolean           phosh_monitor_is_builtin (PhoshMonitor *monitor);
gboolean           phosh_monitor_is_flipped (PhoshMonitor *monitor);
guint              phosh_monitor_get_rotation (PhoshMonitor *monitor);
void               phosh_monitor_set_power_save_mode (PhoshMonitor *self,
                                                      PhoshMonitorPowerSaveMode mode);
