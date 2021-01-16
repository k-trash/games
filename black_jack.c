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
	gtk_widget_set_size_request(window, 600, 400);
	telop_label = gtk_label_new("PLAYING");
	setGui();
	card_back = gtk_image_new_from_file("./cards/back.png");

	g_signal_connect(G_OBJECT(button_hit), "clicked", G_CALLBACK(addCards), player_hbox);
	g_signal_connect(G_OBJECT(button_stand), "clicked", G_CALLBACK(finishGame), NULL);

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
