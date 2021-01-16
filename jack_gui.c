#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
	showCards(choice_card, (GtkWidget*)user_data_, true);
}

void showCards(Card target_card_, GtkWidget *target_box_, bool show_flag_){
	GtkWidget *next_image;
	Marks card_mark;
	char image_name[30] = {"./cards/"};
	char number_name[3];
	static bool finish_flag = false;

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

	sprintf(number_name, "%d", target_card_.number);

	strcat(image_name, number_name);
	strcat(image_name, ".png");

	next_image = gtk_image_new_from_file(image_name);
	gtk_box_pack_start(GTK_BOX(target_box_), next_image, TRUE, TRUE, 0);
	
	if(show_flag_ == true){
		gtk_widget_show_all(window);
	}

	if(calcCard(player_card) > 21 && finish_flag == false){
		finish_flag = true;
		finishGame(NULL, NULL);
	}
}

void finishGame(GtkWidget *button_, gpointer user_data_){
	gtk_container_remove(GTK_CONTAINER(window), vbox);
	vbox = gtk_vbox_new(FALSE, 2);
	dealer_hbox = gtk_hbox_new(FALSE, 2);
	player_hbox = gtk_hbox_new(FALSE, 2);
	button_hbox = gtk_hbox_new(FALSE, 2);
	button_hit = gtk_button_new_with_label("Hit");
	button_stand = gtk_button_new_with_label("Stand");
	button_quit = gtk_button_new_with_label("Quit");
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_pack_start(GTK_BOX(vbox), dealer_hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), player_hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button_hbox, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(button_hbox), button_hit, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(button_hbox), button_stand, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(button_hbox), button_quit, TRUE, TRUE, 0);
	g_signal_connect(G_OBJECT(button_quit), "clicked", G_CALLBACK(quitButtonClicked), NULL);

	for(int i=0;i<dealer_card.card_count;i++){
		showCards(dealer_card.dealed_card[i], dealer_hbox, false);
	}

	for(int i=0;i<player_card.card_count;i++){
		showCards(player_card.dealed_card[i], player_hbox, false);
	}

	gtk_widget_show_all(window);
}
