#include "jack_header.h"
#include <stdlib.h>	//rand関数用

//カードをランダムに引く 戻り値:引いたカード 引数:cards[]
Card chooseCard(Card *cards_){
	unsigned short int rand_num = rand() % (DEC_NUM * 52);

	while(cards_[rand_num].flag == 1){	//すでに引かれていたら引き直す
		rand_num = rand() % (DEC_NUM * 52);
	}

	cards_[rand_num].flag = 1;

	return cards_[rand_num];
}

//カードの合計値を計算 戻り値:合計値 引数:player_card/dealer_card
unsigned short int calcCard(DealedCard target_card_){
	unsigned short int eleven_num = 0;	//Aの枚数
	unsigned short int card_sum = 0;	//合計
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

	for(short int i=0;i<eleven_num;i++){	//Aの処理
		if(card_sum > 11){
			break;
		}else{
			card_sum += 10;
		}
	}

	return card_sum;
}
