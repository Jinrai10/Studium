#include<stdio.h>

int Aufgabe2a(){
    int n = 0;
    printf("Aufgabe2a:\n");
    printf("Gib eine Zahl ein: \n");
    scanf("%i", &n);

    printf("Summe der Zahlen: %i\n", (n*(n+1))/2);
    return 0;
}

int Aufgabe2b(){
    int n = 0;
    printf("Aufgabe2b:\n");
    printf("Gib eine Zahl ein: \n");
    scanf("%i", &n);

    printf("Summe der Quadratzahlen: %i\n", (n*(n+1)*(2*n+1)/6));
    return 0;
}

int Aufgabe3(){
    printf("Aufgabe3:\n");
    int n = 0;
    int prim = 1;
    printf("Geben sie eine positive ganze Zahl ein:\n");
    scanf("%i", &n);

    if (n < 0) {
        printf("Fehler! Die eingegebene Zahl war negativ!\n");
    }else{

        for (int i = 2;i<n; i++){
            if (n%i == 0){
                prim = 0;
            }
        }
        if (prim){
            printf("Ja");
        }else{
            printf("Nein");
        }
        printf("\n");
    }

    return 0;
}

int main(){
    Aufgabe2a();
    printf("\n");
    Aufgabe2b();
    printf("\n");
    Aufgabe3();

    return 0;
}
