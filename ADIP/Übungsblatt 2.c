#include <stdio.h>
/*
    Author:
        Simon Liessem   3100948
        Jan Simon Mathy 3206479
        Vincent Pamatat 3187769
        Nicolas Gassen  3230009
        Marc Flintrop   3208023
*/


void aufgabe1() {
    printf("--------------------\n \nAufgabe 1:\n \n");
    char x1, x2, result;

    // Beispiel 1
    x1 = 35;
    x2 = 85;
    result = x1 + x2;
    printf("Beispiel 2: %hi + %hi = %hi\n", x1, x2, result);

    // Beispiel 2
    x1 = 85;
    x2 = 85;
    result = x1 + x2;
    printf("Beispiel 2: %hi + %hi = %hi\n", x1, x2, result);
}

long fib_rec(long n) {
    if(n < 2) return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

void fib_even (int n) {
    unsigned long long f0 = 0;
    unsigned long long f1 = 1;
    unsigned long long t = 0;
    for (int i = 0;i<n;i++) {
        printf("%i: %llu\n", i+1, f0);
        t = f1+f0;
        f0 = f1+t;
        f1 = t+f0;
    }
}

void aufgabe2() {
    printf("--------------------\n \nAufgabe 2:\n \n");
    long n = 6;
    printf("Die Fibonaccizahl von %ld ist %ld\n", n, fib_rec(n));

    fib_even(50);
}

int vollkommen(int n){
    int m = n;
    for(int i = 1;i<n;i++){
        if(n%i == 0){
            m=m-i;
        }
    }
    if (m == 0) return 1;

    return 0;
}

int defizient(int n){
    int m = 0;
    for(int i = 1;i<n;i++){
        if(n%i == 0){
            m=m+i;
        }
    }
    if (m < n) return 1;

    return 0;
}

int vollkommeneZahlenKleinerAls(int r){
    for(int i = 0;i<r;i++){
        if(vollkommen(i)) printf("%i\n", i);
    }

    return 0;
}

int AnzahlAnDefizientenZahlenKleinerAls(int r){
    int counter = 0;
    for(int i = 0;i<r;i++) {
        if (defizient(i)) counter++;
    }

    return counter;
}

void aufgabe3(int n, int r){
    printf("--------------------\n \nAufgabe 3:\n \n");
    if(vollkommen(n)) printf("Die Zahl %i ist vollkommen!\n", n);

    if(defizient(n)) printf("Die Zahl %i ist defizient!\n", n);

    printf("Vollkommene Zahlen Kleiner als %i\n", r);
    vollkommeneZahlenKleinerAls(r);
    printf("Anzahl an Defizienten Zahlen kleiner als %i: %i\n", r, AnzahlAnDefizientenZahlenKleinerAls(r));
}

void aufgabe4(){
    printf("--------------------\n \nAufgabe 4:\n \n");
    for(int i = 1; i<=10;i++){
        for(int j = 1; j<= 10;j++){
            printf("%i x %i = %i\n", j, i, i*j);
        }
    }
}

int potenz(int a, int n){
    if(n == 0) return 1;
    return a * potenz(a, n-1);
}

int potenz2(int a, int n){
    if (n == 0) return 1;
    if (n%2 == 0) return potenz2(a, n/2)*potenz2(a, n/2);
    return a * potenz2(a, (n-1)/2) * potenz2(a, (n-1)/2);
}

void aufgabe5(){
    printf("--------------------\n \nAufgabe 5:\n \n");

    printf("%i\n", potenz(2, 4));

    printf("%i\n", potenz2(2, 4));
}

int main(){
    aufgabe1();
    /* Ergebnis:
        Kompilierung:
            Warning: format specifies type 'short' but the argument has type 'char'
        Ausführen:
            Das erste Beispiel funktioniert wie erwartet und gibt das richtige Ergebnis aus.
            Beim zweiten ist das Ergebnis der Rechnung vorkommen unerwartet statt 85 + 85 = 170 erhalten wir
            85 + 85 = -86 (Zweierkomplementdarstellung)
    */
    aufgabe2();
    aufgabe3(51, 499);
    aufgabe4();
    aufgabe5();

    return 0;
}
