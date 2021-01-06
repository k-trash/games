#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SET_NUM 1	//使うカードのセット数

typedef enum Marks = {SPADE, CLUB, HEART, DIAMOND}Marks;

typedef struct Card{
	unsigned short int number : 8;
	unsigned short int mark : 2;
	unsigned short int flag : 1;
}Card;

unsigned short int choiceCard(Card *cards_);	//カードを選ぶ関数 戻り値:何枚目のカードか 引数:カードの配列

int main(void){
	Card cards[SET_NUM*52];
	unsigned short int count = 0;

	srand((unsigned int)time(NULL));
	
	for(short int i = 0;i < 4;i++){		//以下カードの割当
		for(short int j = 1;j <= 13;j++){
			for(short int k = 0;k < SET_NUM;k++){
				cards[count].number = j;
				cards[count].mark = i;
				cards[count].flag = 0;
				count++;
			}
		}
	}

	

	return 0;
}

//カードを選ぶ関数 戻り値:何枚目のカードか 引数:カードの配列
unsigned short int choiceCard(Card *cards_){
	unsigned short int rand_num = rand() % (SET_NUM * 52);
	
	while(cards_[rand_num].flag == 1){
		rand_num = rand() % (SET_NUM * 52);
	}

	cards_[rand_num].flag = 1;

	return rand_num;
}
