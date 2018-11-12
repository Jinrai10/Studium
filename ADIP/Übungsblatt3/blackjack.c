#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
    Author:
        Simon Liessem   3100948
        Jan Simon Mathy 3206479
        Vincent Pamatat 3187769
        Nicolas Gassen  3230009
        Marc Flintrop   3208023
*/

void initializegenerator(){
		srand(time(NULL));
}

int karteZiehen(){
	return ((rand()%8)+2);
}

int main(void){
	initializegenerator();
	int player = 0, dealer = 0, playing = 1;
	char str[4];

	dealer += karteZiehen();
	player += karteZiehen();

	printf("player: %i, dealer: %i\n", player, dealer);
	while(playing == 1){
		if(player > 21){
			printf("you lost\n");
			return 0;
		}else if (player == 21){
			printf("you won\n");
			return 0;
		}

		printf("draw or stay?\n");
		scanf("%s", str);

		if(strcmp(str, "stay") == 0){
			playing = 0;
		}else if(strcmp(str, "draw") == 0){
			player += karteZiehen();
			printf("player: %i\n", player);
		}
	}

	while(dealer<= 16){
		dealer+=karteZiehen();
	}
	printf("dealer: %i\n", dealer);

	if(dealer < player || dealer > 21){
		printf("you won\n");
	}else{
		printf("you lost\n");
	}

	return 0;
}
