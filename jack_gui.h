#pragma once

GtkWidget *window;
GtkWidget *vbox;
GtkWidget *user_cards;

void quitButtonClicked(GtkWidget *button_, gpointer user_data_);

void addCards(GtkWidget *button_, gpointer user_data_);
