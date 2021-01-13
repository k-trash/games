#pragma once

#define DEC_NUM 1	//プレイ時のデック数

typedef enum Marks {SPADE, CLUB, HEART, DIAMOND}Marks;

typedef struct Card{
	unsigned short int number : 8;
	unsigned short int mark : 2;
	unsigned short int flag : 1;
}Cards;

Card cards[DEC_NUM*52];

Card choiceCard(Card **cards_);
