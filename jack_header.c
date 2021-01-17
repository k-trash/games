#include "jack_header.h"
#include <stdlib.h>

Card chooseCard(Card *cards_){
	unsigned short int rand_num = rand() % (DEC_NUM * 52);

	while(cards_[rand_num].flag == 1){
		rand_num = rand() % (DEC_NUM * 52);
	}

	cards_[rand_num].flag = 1;

	return cards_[rand_num];
}

unsigned short int calcCard(DealedCard target_card_){
	unsigned short int eleven_num = 0;
	unsigned short int card_sum = 0;
	for(short int i=0;i<target_card_.card_count;i++){
		if(target_card_.dealed_card[i].number > 10){
			card_sum += 10;
		}else if(target_card_.dealed_card[i].number == 1){
			card_sum += 1;
			eleven_num++;
		}else{
			card_sum += target_card_.dealed_card[i].number;
		}
	}

	for(short int i=0;i<eleven_num;i++){
		if(card_sum > 11){
			break;
		}else{
			card_sum += 10;
		}
	}

	return card_sum;
}
