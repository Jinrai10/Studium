#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int deck[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

void initializegenerator() {
    srand(time(NULL));
}

void remove_element(int *array, int index, int array_length) {
   for(int i = index; i < array_length - 1; i++) array[i] = array[i + 1];
}

int isvalueinarray(int val, int *arr, int size){
    for (int i=0; i < size; i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

int getKarte() {
    int zufall = 0;
	do {
 	    zufall = 2 + (rand() % 9);
	} while(isvalueinarray(zufall, deck, 9) == -1);
	remove_element(deck, isvalueinarray(zufall, deck, 9), 9);
				
    return zufall;
}

int compare(char str[], char str2[]) {
	if (strcmp(str, str2) == 0) {
		return 1;
	}
	return 0;
}



int main() {
    initializegenerator();
    char str[5] = "";
    char stay[] = "stay";
    char give[] = "give";
	char *p;
    int endTurn = 1;

    int kartenanzahlSpieler = 0;
    int kartenanzahlDealer = getKarte();    
    printf("Die gezogene Kart war: %i\n", kartenanzahlDealer);
    
	while(kartenanzahlSpieler < 21) {
		printf("Momentane Kartenanzahl: %i\n", kartenanzahlSpieler);
		while (compare(str, stay) == 0 && compare(str, give) == 0) {
			printf("'stay' oder 'give'?\n");
			fgets(str, 5, stdin);
			if((p=strchr(str, '\n'))) {//check exist newline
                *p = 0;
            } else {
                scanf("%*[^\n]");scanf("%*c");//clear upto newline
            }
		}
		if(compare(str, give)) {
			kartenanzahlSpieler += getKarte();
		}else break;
		strncpy(str, "", 5);
	}
	
	if (kartenanzahlSpieler == 21) {
		printf("Du hast gewonnen!\nKartenzahl: %i\n", kartenanzahlSpieler);
		return 0;
	}else if (kartenanzahlSpieler > 21) {
		printf("Du hast verloren!\nKartenzahl: %i\n", kartenanzahlSpieler);
		return 0;
	}
	
	while (kartenanzahlDealer <= 16) {
		kartenanzahlDealer += getKarte();
	}
	
	if (kartenanzahlDealer < kartenanzahlSpieler) {
		printf("Du hast gewonnen!\nDer Dealer hatte eine niedrigere Kartenzahl: %i\n", kartenanzahlDealer);
		printf("Deine Kartenzahl: %i\n", kartenanzahlSpieler);
	}else if(kartenanzahlDealer > 21) {
		printf("Du hast gewonnen!\nDer Dealer hat mit seiner Kartenzahl 21 überschritten.\nDeine Kartenzahl: %i\n", kartenanzahlSpieler);
	}else {
		printf("Dealer hat gewonnen mit einer Kartenzahl von: %i\n", kartenanzahlDealer);
		printf("Deine Kartenzahl: %i\n", kartenanzahlSpieler);
	}

    return 0; 
}


