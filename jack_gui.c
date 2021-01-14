#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jack_gui.h"
#include "jack_header.h"

void quitButtonClicked(GtkWidget *button_, gpointer user_data_){
	gtk_main_quit();
}

void addCards(GtkWidget *button_, gpointer user_data_){
	GtkWidget *next_image;
	Card ret_card;
	Marks card_mark;
	char image_name[30] = {"./cards/"};
	char number_name[3];

	ret_card = choiceCard(cards);
	card_mark = ret_card.mark;
	switch(card_mark){
		case SPADE:
			strcat(image_name, "spade_");
			break;
		case CLUB:
			strcat(image_name, "club_");
			break;
		case HEART:
			strcat(image_name, "heart_");
			break;
		case DIAMOND:
			strcat(image_name, "dia_");
			break;
	}
	
	if(ret_card.number > 10){
		ret_card.number = 10;
	}

	sprintf(number_name, "%d", ret_card.number);

	strcat(image_name, number_name);
	strcat(image_name, ".png");

	next_image = gtk_image_new_from_file(image_name);
	gtk_box_pack_start(GTK_BOX(user_data_), next_image, TRUE, TRUE, 0);
	gtk_widget_show_all(window);
}
