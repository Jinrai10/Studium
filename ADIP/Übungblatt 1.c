#include<stdio.h>

/*
Aufgabe1:
    input: zahl n
    output: Liste mit Primfaktoren

    l = Liste von Ganzzahlen

    für i als 2 und alle ungeraden Zahlen kleiner n/2 + 1 und grösser 2  wiederhole
        wenn n mod i = 0
            erweitere l mit i
            solange n mod i = 0
                n = n/i
        wenn i > n
            ende die schleife

    gib die liste zurück

*/

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
        return 1;
    }

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
