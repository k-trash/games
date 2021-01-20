#pragma once

#include <stdbool.h>	//bool型が使いたい
#include "jack_header.h"

bool finish_flag;	//finishGameとshowCardsの間で無限ループが生まれるのを防ぐ

GtkWidget *window;
GtkWidget *vbox;
GtkWidget *dealer_hbox;
GtkWidget *telop_hbox;
GtkWidget *player_hbox;
GtkWidget *button_hbox;
GtkWidget *button_hit;
GtkWidget *button_stand;
GtkWidget *button_again;
GtkWidget *button_quit;
GtkWidget *telop_label;

//プログラムの終了 Quitボタンに対応
void quitButtonClicked(GtkWidget *button_, gpointer user_data_);

//ゲームのリセット Againボタンに対応
void startAgain(GtkWidget *button_, gpointer user_data_);

//Guiの設定
void setGui(void);

//カードを引く Hitボタンに対応
void addCards(GtkWidget *button_, gpointer user_data_);

//カードの描画
void showCards(Card target_card_, GtkWidget *target_box_, bool show_flag_);

//プレイヤーのターンの終了 Standボタンに対応
void finishGame(GtkWidget *button_, gpointer user_data_);
