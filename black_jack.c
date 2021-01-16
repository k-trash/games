#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include "jack_gui.h"
#include "jack_header.h"

int main(int argc, char *argv[]){
	unsigned short int count = 0;
	GtkWidget *card_back;

	player_card.card_count = 0;
	dealer_card.card_count = 0;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	vbox = gtk_vbox_new(FALSE, 2);
	player_hbox = gtk_hbox_new(FALSE, 2);
	dealer_hbox = gtk_hbox_new(FALSE, 2);
	button_hbox = gtk_hbox_new(FALSE, 2);
	button_hit = gtk_button_new_with_label("Hit");
	button_stand = gtk_button_new_with_label("Stand");
	button_quit = gtk_button_new_with_label("Quit");
	card_back = gtk_image_new_from_file("./cards/back.png");

	gtk_widget_set_size_request(window, 600, 400);
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_pack_start(GTK_BOX(vbox), dealer_hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), player_hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button_hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(button_hbox), button_hit, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(button_hbox), button_stand, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(button_hbox), button_quit, TRUE, TRUE, 0);
	g_signal_connect(G_OBJECT(button_hit), "clicked", G_CALLBACK(addCards), player_hbox);
	g_signal_connect(G_OBJECT(button_stand), "clicked", G_CALLBACK(finishGame), NULL);
	g_signal_connect(G_OBJECT(button_quit), "clicked", G_CALLBACK(quitButtonClicked), NULL);

	srand((unsigned int)time(NULL));
	
	for(short int i = 0;i < 4;i++){		//以下カードの割当
		for(short int j = 1;j <= 13;j++){
			for(short int k = 0;k < DEC_NUM;k++){
				cards[count].number = j;
				cards[count].mark = i;
				cards[count].flag = 0;
				count++;
			}
		}
	}

	gtk_box_pack_start(GTK_BOX(dealer_hbox), card_back, TRUE, TRUE, 0);
	dealer_card.dealed_card[0] = chooseCard(cards);
	dealer_card.card_count++;
	addCards(NULL, dealer_hbox);
	addCards(button_hit, player_hbox);
	addCards(button_hit, player_hbox);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
