

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG



struct card {
	char shortName; //S , H , D , C
	char fullName[8]; //Spade, Heart, Diamond, Club
	int rank; // 1 ~ 13 
};

struct card deck[52];

int deck_deal_rec[52]; //remember what card has been deal 
int deck_deal_count; //count how many card has been deal

void cards_init();
void cards_print();
void cards_shuffle(int shuffle_time);
void cards_get_info(char* info, int card_pos);

void deck_deal_clean();
 int deck_deal_send_card();

int main() 
{
	struct card c;
	srand(time(NULL));
	int i;
	int pos;

	deck_deal_clean();
	cards_init();

	cards_print();
	
	printf("\nshuffle start \n");
	cards_shuffle(100);
	printf("\nshuffle end \n");

	printf("\nPrint the cards information after shuffle\n");
	cards_print();

	printf("\nStart to send playing card \n");
	i = 1;
	static char info[8];
	while ( -1 != (pos=deck_deal_send_card()) ){
		cards_get_info(info,pos);
		printf("[%02d]_th card = %s\n", i,info);
		i++;
	}
	printf("Sending card finish \n");

	return 0;
}

#if 1
void cards_shuffle(int shuffle_time) {
	int i;
	int p1,p2;
	struct card tmp;
#ifdef DEBUG
	char cardL[8];
	char cardR[8];
#endif 

	for(i = 0; i<shuffle_time; i++) {
		p1 = rand()%52; 
		p2 = rand()%52;

#ifdef DEBUG		
		cards_get_info(cardL,p1);
		cards_get_info(cardR,p2);
		printf("swap(%d,%d) --> swap(%s,%s)\n", p1,p2,cardL, cardR);
#endif		
		tmp = deck[p1];
		deck[p1] = deck[p2];
		deck[p2] = tmp; 
	}
}

#endif

void cards_init() {
	static char shortNames[] = {'S','H','D','C'};//SHDC
	static char fullNames[][8] = {"Shade","Heart","Diamond","Club"}; //Spade, Heart, Diamond, Club
	int i;
	for ( i = 0; i < 52; i++) {
		deck[i].shortName = shortNames[i/13];
		strcpy(deck[i].fullName,fullNames[i/13]);
		deck[i].rank = i%13 + 1;
	}
}

void cards_print() {
	int i;
	for(i = 0; i< 52; i++) {
		printf("%d %c %s %d \n", i, deck[i].shortName, deck[i].fullName, deck[i].rank);
	}
}

void cards_get_info(char* info, int card_pos) {
	sprintf(info, "%c%02d", deck[card_pos].shortName, deck[card_pos].rank);
}


void deck_deal_clean() {
	deck_deal_count = 0;
}

 int deck_deal_send_card() {
	if( ! (deck_deal_count < 52)) return -1;
	//return -1 when there is no card to send.
	int pos;//pos:= position for candicated card
	int is_repeat; 
	do {
		pos = rand()%52;
		is_repeat = 0;
		int i;
		for (i = 0; i < deck_deal_count; i++ ) {
			if(deck_deal_rec[i]  == pos) {
				is_repeat =1;
				break;
			}
		}
	} while(is_repeat == 1);
	deck_deal_rec[deck_deal_count++] = pos;
	return pos;
}


