#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int randomInt(int start, int end) {
	return start + (rand() % (unsigned int) (end-start+ 1));
}

void randomaArr() {
	srand(time(NULL));
	
	int arr[10][10];
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = randomInt(1, 1000);
			printf("[%i]\t", arr[i][j]);
			
		}
		printf("\n");
	}
	
	int x = 20;
	printf("%i\n", x << 2);
	
	return;
}

void geldautomat(){

	int Karten_ID = 1234;
	int Kontostand = 10000;
    int input;

    while(1){

        printf("Karte ID eingeben: ");
        int check = scanf("%i",&input);
        if(check != 1){
            printf("Vorgang abgebrochen ..\n");
			break;
        }else if(input != Karten_ID) {
        	printf("Karten_ID existiert nicht!\n");
        	break;
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
            printf("Sie haben keine Zahl eingegeben!\n");
            printf("Vorgang abgebrochen ...\n");
            break;
        }
        if(input == 10 || input == 25 || input == 50 || input == 100 || input == 200 || input == 500){
        	Kontostand -= input;
		}else {
			printf("Die Eingabe war nicht innerhalb des angegebenen Bereiches! -> Abbruch\n");
		}
    }
}

void aufgabe2(int n){
	int sum = 0;
	for (int i = 1; i<=n; i+=2) {
		sum+=i;
	}
	printf("%i_%i\n", sum, n);
}

int prim(int c) {
	double root;
	for (int i = 2; i<10000;i++) {
		root = sqrt((double) c);
		if (i - root > 0) {
			return 1;
		}else if(c % i == 0){
			return 0;
		}
	}
	return 0;
}

void aufgabe3() {	
	for (int i = 40000; i<100000; i++) {
		if (prim(i) == 1) {
			printf("%i\n", i);
		}
	}
}

int ggT(int a, int b) {
	if (a == 0) {
		return b;
	}else if(b == 0) {
		return a;	
	}else {
		if (a>b) {
			return ggT(a-b, b);
		}else {
			return ggT(b, b-a);
		}
		
	}
}

void aufgabe4() {
	printf("%i\n", ggT(13, 45));
	return;
}

void aufgabe5(int n) {
	double sum = 0;
	for (int i=1; i < n; i++) {
		sum+= 1./(i*i);
	}	
	printf("%lf\n", sum);
}

int main(){
	/*for (int i = 1; i<=15; i++) {
		aufgabe2(i);
	}*/
	aufgabe5(10000);
	return 0;
}
	
