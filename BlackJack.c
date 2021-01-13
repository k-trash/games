#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SET_NUM 1	//�g���J�[�h�̃Z�b�g��

typedef enum Marks {SPADE, CLUB, HEART, DIAMOND}Marks;

typedef struct Card{
	unsigned short int number : 8;
	unsigned short int mark : 2;
	unsigned short int flag : 1;
}Card;

unsigned short int choiceCard(Card *cards_);	//�J�[�h��I�Ԋ֐� �߂�l:�����ڂ̃J�[�h�� ����:�J�[�h�̔z��
unsigned short int calc(int sum, int num);

int main(void){
	Card cards[SET_NUM*52];
	unsigned short int count = 0;
	unsigned short int i;

	srand((unsigned int)time(NULL));
	
	for(i = 0;i < 4;i++){		//�ȉ��J�[�h�̊���
		for(short int j = 1;j <= 13;j++){
			for(short int k = 0;k < SET_NUM;k++){
				cards[count].number = j;
				cards[count].mark = i;
				cards[count].flag = 0;
				count++;
			}
		}
	}
	
	unsigned short int player[5];
	unsigned short int dealer[5];
	unsigned short int sump = 0, sumd = 0;
	
	for(i = 0; i < 2; i++){
		player[i] = choiceCard(cards);
		sump = calc(sump, cards[player[i]].number);
		printf("%d %d\n", cards[player[i]].number, cards[player[i]].mark);
	}
	for(i = 0; i < 2; i++){
		dealer[i] = choiceCard(cards);
		sumd = calc(sumd, cards[dealer[i]].number);
		printf("%d %d\n", cards[dealer[i]].number, cards[dealer[i]].mark);
	}
	
	//�v���C���[�̃^�[��
	unsigned short int signal;
	signal = 1;
	i = 2;
	printf("�`�v���C���[�̃^�[���`\n");
	while(signal){
		printf("���Ȃ��̍��v:%d\n�q�b�g�F0 �X�^���h�F1\n", sump);
		int respones;
		scanf("%d", &respones);
		
		if(respones == 0){
			player[i] = choiceCard(cards);
			printf("%d %d���o�܂����B\n", cards[player[i]].number, cards[player[i]].mark);
			sump = calc(sump, cards[player[i]].number);
			if(sump > 21){
				printf("�v���C���[���o�[�X�g\n");
				sump = 0;
				signal--;
			}
		}else if(respones == 1){
			signal--;
		}else{
			i--;
		}
		i++;
	}
	
	//�f�B�[���[�̃^�[��
	signal = 1;
	i = 2;
	printf("�`�f�B�[���[�̃^�[���`\n");
	while(signal){
		printf("�f�B�[���[�̍��v:%d\n", sumd);
		if(sumd < 17 || sumd < sump){
			dealer[i] = choiceCard(cards);
			sumd = calc(sumd, cards[dealer[i]].number);
			printf("�f�B�[���[�̓q�b�g��I���B\n%d %d���o�܂����B\n", cards[dealer[i]].number, cards[dealer[i]].mark, sumd);
			if(sumd > 21){
				printf("�f�B�[���[���o�[�X�g\n");
				sumd = 0;
				signal--;
			}
		}else if(sumd > sump || sumd == 21 || sumd == sump){
			signal--;
		}
		i++;
	}
	
	printf("Player:%d Dealer:%d\n", sump, sumd);
	if(sump > sumd){
		printf("You Win\n");
	}else if(sump < sumd || sump == 0){
		printf("You Lose\n");
	}else{
		printf("��������\n");
	}
	

	return 0;
}

unsigned short int choiceCard(Card *cards_){
	unsigned short int rand_num = rand() % (SET_NUM * 52);
	
	while(cards_[rand_num].flag == 1){
		rand_num = rand() % (SET_NUM * 52);
	}

	cards_[rand_num].flag = 1;

	return rand_num;
}

unsigned short int calc(int sum, int num){
	if(num >= 10){
		sum += 10;
	}else{
		sum += num;
	}
	
	return sum;
}