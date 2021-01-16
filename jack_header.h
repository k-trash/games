#pragma once

#define DEC_NUM 1	//プレイ時のデック数

typedef enum Marks {SPADE, CLUB, HEART, DIAMOND}Marks;

typedef struct Card{
	unsigned short int number : 8;
	unsigned short int mark : 2;
	unsigned short int flag : 1;
}Card;

typedef struct DealedCard{
	Card dealed_card[21];
	unsigned short int card_count;
}DealedCard;

Card cards[DEC_NUM*52];

DealedCard player_card;
DealedCard dealer_card;

Card chooseCard(Card *cards_);
unsigned short int calcCard(DealedCard target_card_);
