#pragma once

#include "jack_header.h"

GtkWidget *window;
GtkWidget *vbox;
GtkWidget *user_cards;

void quitButtonClicked(GtkWidget *button_, gpointer user_data_);

void addCards(GtkWidget *button_, gpointer user_data_);

void showCards(Card target_card_, GtkWidget *target_box_);
