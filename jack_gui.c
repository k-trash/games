#include <gtk/gtk.h>
#include <stdio.h>	//sprintf用
#include <stdlib.h>	//srand用
#include <string.h>	//strcat用
#include <stdbool.h>
#include <time.h>	//srandで使う
#include "jack_gui.h"
#include "jack_header.h"

//プログラムの終了
void quitButtonClicked(GtkWidget *button_, gpointer user_data_){
	gtk_main_quit();
}

void startAgain(GtkWidget *button_, gpointer user_data_){
	unsigned short int count = 0;
	GtkWidget *card_back;		//カードの裏側の画像

	finish_flag = false;
	card_back = gtk_image_new_from_file("./cards/back.png");

	player_card.card_count = 0;
	dealer_card.card_count = 0;
	if((void*)button_ != NULL){	//vboxを定義する前に削除しないようにする
		gtk_container_remove(GTK_CONTAINER(window), vbox);
	}
	telop_label = gtk_label_new("PLAYING");
	setGui();

	//関数とボタンの紐付け
	g_signal_connect(G_OBJECT(button_hit), "clicked", G_CALLBACK(addCards), player_hbox);
	g_signal_connect(G_OBJECT(button_stand), "clicked", G_CALLBACK(finishGame), NULL);

	srand((unsigned int)time(NULL));

	for(short int i = 0;i < 4;i++){
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
	dealer_card.card_count = 1;
	addCards(NULL, dealer_hbox);
	addCards(button_hit, player_hbox);
	addCards(button_hit, player_hbox);

	gtk_widget_show_all(window);	//描画
}

//GUIの設定 基本的におまじない
void setGui(void){
	vbox = gtk_vbox_new(FALSE, 2);
	dealer_hbox = gtk_hbox_new(FALSE, 2);
	player_hbox = gtk_hbox_new(FALSE, 2);
	telop_hbox = gtk_hbox_new(FALSE, 2);
	button_hbox = gtk_hbox_new(FALSE, 2);
	button_hit = gtk_button_new_with_label("Hit");
	button_stand = gtk_button_new_with_label("Stand");
	button_again = gtk_button_new_with_label("Again");
	button_quit = gtk_button_new_with_label("Quit");
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_pack_start(GTK_BOX(vbox), dealer_hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), telop_hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), player_hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button_hbox, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(telop_hbox), telop_label, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(button_hbox), button_hit, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(button_hbox), button_stand, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(button_hbox), button_again, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(button_hbox), button_quit, TRUE, TRUE, 0);
	g_signal_connect(G_OBJECT(button_quit), "clicked", G_CALLBACK(quitButtonClicked), NULL);
	g_signal_connect(G_OBJECT(button_again), "clicked", G_CALLBACK(startAgain), NULL);

	for(short int i=0;i<dealer_card.card_count;i++){
		showCards(dealer_card.dealed_card[i], dealer_hbox, false);
	}

	for(short int i=0;i<player_card.card_count;i++){
		showCards(player_card.dealed_card[i], player_hbox, false);
	}
}

//カードの追加 実際にはほぼshowCards任せ
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

//カードの表示 表示しないようにもできる(その場合は準備のみ)
void showCards(Card target_card_, GtkWidget *target_box_, bool show_flag_){
	GtkWidget *next_image;		//表示する画像
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

	sprintf(number_name, "%d", target_card_.number);

	strcat(image_name, number_name);
	strcat(image_name, ".png");		//画像の名前の完成

	next_image = gtk_image_new_from_file(image_name);
	gtk_box_pack_start(GTK_BOX(target_box_), next_image, TRUE, TRUE, 0);
	
	if(show_flag_ == true){
		gtk_widget_show_all(window);
	}

	//プレイヤーがバーストしていたらターンの終了へ
	if((calcCard(player_card) > 21) && finish_flag == false){
		finish_flag = true;	//これをしないと無限ループが生まれる
		finishGame(NULL, NULL);
	}
}

//プレイヤーのターンの終了
void finishGame(GtkWidget *button_, gpointer user_data_){
	short int dealer_sum;
	short int player_sum;
	
	gtk_container_remove(GTK_CONTAINER(window), vbox);
	telop_label = gtk_label_new("DEALER TURN");
	setGui();		//ディーラーのカードをオープンする

	gtk_widget_show_all(window);

	while(calcCard(dealer_card) <= 16){	//ディーラーが17以上になるまで引き続ける
		addCards(NULL, dealer_hbox);
	}

	gtk_container_remove(GTK_CONTAINER(window), vbox);

	player_sum = (short int)calcCard(player_card);
	dealer_sum = (short int)calcCard(dealer_card);
	if(player_sum > 21){		//ブラックジャックのときの処理
		player_sum = -1;
	}else if(player_sum == 21 && player_card.card_count == 2){	//バーストしたときの処理
		player_sum = 22;
	}
	if(dealer_sum > 21){		//プレイヤーのときと基本的に同じ
		dealer_sum = 0;		//プレイヤーがバーストしたら必ず勝てるので0
	}else if(dealer_sum == 21 && dealer_card.card_count == 2){
		dealer_sum = 22;
	}

	if(dealer_sum < player_sum){
		telop_label = gtk_label_new("YOU WIN!");
	}else if(dealer_sum > player_sum){
		telop_label = gtk_label_new("YOU LOSE");
	}else{
		telop_label = gtk_label_new("Draw");
	}

	setGui();	//結果を書いて再描画

	gtk_widget_show_all(window);
}
