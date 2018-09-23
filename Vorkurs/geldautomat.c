#include <stdio.h>
#include <stdlib.h>

int Karten_ID = 1234;
int Kontostand = 10000;

int main() {
    int input;

    while(1){

        printf("Karte ID eingeben: ");
        int check = scanf("%i",&input);
        if(check != 1){
            printf("Vorgang abgebrochen ..\n");
            return 0;
        }else if(input != Karten_ID) {
        	printf("Karten_ID existiert nicht!\n");
        	return 0;
        }
        printf("Der Kontostand des angegebenen Kontos beträgt: '%i'\n", Kontostand);		
        
        printf("Wie viel Geld möchten sie abheben?\n");
        printf("10 €\n");
        printf("25 €\n");
        printf("50 €\n");
        printf("100 €\n");
        printf("200 €\n");
        printf("500 €\n");
        printf("Betrag auswählen :\n");
        printf("(Alle anderen Eingaben führen zum Abbruch)\n");
        check = scanf("%i",&input);
        
        if(check != 1){
            printf("Sie haben keine Zahl eingegeben\n");
            printf("Vorgang abgebrochen ...\n");
            return 0;
        }
        if(input == 10 || input == 25 || input == 50 || input == 100 || input == 200 || input == 500){
        	Kontostand -= input;
		}else {
			printf("Die Eingabe war nicht innerhalb des angegebenen Bereiches! -> Abbruch\n");
			return 0;	
		}
    }
    
    return 0; 
}
