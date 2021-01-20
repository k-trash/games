#pragma once

#define DEC_NUM 1	//プレイ時のデック数

typedef enum Marks {SPADE, CLUB, HEART, DIAMOND}Marks;	//マークのenum

typedef struct Card{
	unsigned short int number : 4;	//カードの数字
	unsigned short int mark : 2;	//カードのマーク
	unsigned short int flag : 1;	//すでに引かれたかどうかのフラグ
}Card;

typedef struct DealedCard{
	Card dealed_card[21];
	unsigned short int card_count : 5;	//カードを引いた枚数
}DealedCard;

Card cards[DEC_NUM*52];

DealedCard player_card;		//プレイヤーの持ち札
DealedCard dealer_card;		//ディーラーの持ち札

Card chooseCard(Card *cards_);	//ランダムにカードを引く
unsigned short int calcCard(DealedCard target_card_);	//カードの合計を計算する
