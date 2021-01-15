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
	Card choice_card;
	choice_card = chooseCard(cards);
	if((void*)button_ != NULL){
		player_card.dealed_card[player_card.card_count++] = choice_card;
	}else{
		dealer_card.dealed_card[dealer_card.card_count++] = choice_card;
	}
	showCards(choice_card, (GtkWidget*)user_data_);
}

void showCards(Card target_card_, GtkWidget *target_box_){
	GtkWidget *next_image;
	Marks card_mark;
	char image_name[30] = {"./cards/"};
	char number_name[3];

	card_mark = target_card_.mark;
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
	
	if(target_card_.number > 10){
		target_card_.number = 10;
	}

	sprintf(number_name, "%d", target_card_.number);

	strcat(image_name, number_name);
	strcat(image_name, ".png");

	next_image = gtk_image_new_from_file(image_name);
	gtk_box_pack_start(GTK_BOX(target_box_), next_image, TRUE, TRUE, 0);
	gtk_widget_show_all(window);

	if(calcCard(player_card) > 21){
		gtk_main_quit();
	}
}
