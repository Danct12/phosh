/*
 * Copyright (C) 2018 Purism SPC
 * SPDX-License-Identifier: GPL-3.0+
 * Author: Guido Günther <agx@sigxcpu.org>
 */
#pragma once

#include <gtk/gtk.h>

void phosh_cp_widget_destroy (void *widget);
GtkWidget *phosh_get_image_from_gicon (GIcon *icon, int size, int scale);
