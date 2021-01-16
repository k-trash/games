#pragma once

#include <stdbool.h>
#include "jack_header.h"

GtkWidget *window;
GtkWidget *vbox;
GtkWidget *dealer_hbox;
GtkWidget *telop_hbox;
GtkWidget *player_hbox;
GtkWidget *button_hbox;
GtkWidget *button_hit;
GtkWidget *button_stand;
GtkWidget *button_quit;
GtkWidget *telop_label;

void quitButtonClicked(GtkWidget *button_, gpointer user_data_);

void setGui(void);

void addCards(GtkWidget *button_, gpointer user_data_);

void showCards(Card target_card_, GtkWidget *target_box_, bool show_flag_);

void finishGame(GtkWidget *button_, gpointer user_data_);
