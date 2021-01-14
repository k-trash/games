#include "jack_header.h"
#include <stdlib.h>

Card choiceCard(Card *cards_){
	unsigned short int rand_num = rand() % (DEC_NUM * 52);

	while(cards_[rand_num].flag == 1){
		rand_num = rand() % (DEC_NUM * 52);
	}

	cards_[rand_num].flag = 1;

	return cards_[rand_num];
}
