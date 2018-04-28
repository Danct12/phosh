/*
 * Copyright (C) 2018 Purism SPC
 *
 * SPDX-License-Identifier: GPL-3.0+
 */

#ifndef PHOSH_FAVORITES_H
#define PHOSH_FAVORITES_H

#include <gtk/gtk.h>

#define PHOSH_TYPE_FAVORITES (phosh_favorites_get_type())

G_DECLARE_FINAL_TYPE (PhoshFavorites, phosh_favorites, PHOSH, FAVORITES, GtkWindow)

GtkWidget * phosh_favorites_new ();

#endif /* PHOSH_FAVORITES_H */