#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
    Author:
        Simon Liessem   3100948
        Jan Simon Mathy 3206479
        Vincent Pamatat 3187769
        Nicolas Gassen  3230009
        Marc Flintrop   3208023
*/


void aufgabe2(){
    printf("Aufgabe 1 --------------------------\n");
    int n;
    double erg1 = 0, erg2 = 0, t;

    printf("Anzahle der Elemente?:\n");
    scanf("%i", &n);

    double numbers[n];

    //Elemente abfragen und in array einfügen
    for(int i = 0; i < n; i++){
        printf("Zahl %i?\n", (i+1));
        scanf("%lf", &t);
        numbers[i] = t;
    }
    //zahlen in array aufsummieren
    for(int i = 0; i < n; i++){
        erg1 += numbers[i];
    }

    erg1 = erg1/n;

    printf("arithmetisches Mittel:\n");
    printf("%lf\n", erg1);


    for (int i = 0; i < n; i++) {
        erg2 += pow((numbers[i] - erg1), 2);
    }

    erg2 = erg2/(n-1);

    printf("Stichprobenvarianz\n");
    printf("%lf\n", erg2);
}


void aufgabe3(){
        int zahl;
        printf("Zahl zwischen 20 und 69?\n");
        scanf("%i", &zahl);

        if(zahl < 20 || zahl > 69){
            printf("ERROR: Zahl außerhalb des bereiches\n");
            return;
        }

        //ziffern aufteilen
        int d1, d2;
        d1 = zahl%10;
        d2 = zahl/10;

        switch(d1){
          case 0:
            break;
          case 1:
            printf("ein-und-");
          break;

          case 2:
            printf("zwei-und-");
          break;

          case 3:
            printf("drei-und-");
          break;

          case 4:
            printf("vier-und-");
          break;

          case 5:
            printf("fünf-und-");
          break;

          case 6:
            printf("sechs-und-");
          break;

          case 7:
            printf("sieben-und-");
          break;

          case 8:
            printf("acht-und-");
          break;

          case 9:
            printf("neun-und-");
          break;
        }

        switch(d2){
          case 2:
            printf("zwanzig\n");
          break;

          case 3:
            printf("dreißig\n");
          break;

          case 4:
            printf("vierzig\n");
          break;

          case 5:
            printf("fünfzig\n");
          break;

          case 6:
            printf("sechzig\n");
          break;
        }
}

float aufgabe4float(){

    //schriftlich = 0.0000317460317460317460317460317460317460

    float erg = 0;
    float x[5];
    x[0] = 10000.0;
    x[1] = ((-1.0 * pow(10, -3))/9.0);
    x[2] = (25.0 * pow(10, 2));
    x[3] = ((1.0 * pow(10, -3))/7.0);
    x[4] = (-12.5 * pow(10, 3));

    for(int i = 0; i < 5; i++){
      erg += x[i];
    }

    return erg;
}



double aufgabe4double(){

    //schriftlich = 0.0000317460317460317460317460317460317460

    double erg = 0;
    double x[5];
    x[0] = 10000.0;
    x[1] = ((-1.0 * pow(10, -3))/9.0);
    x[2] = (25.0 * pow(10, 2));
    x[3] = ((1.0 * pow(10, -3))/7.0);
    x[4] = (-12.5 * pow(10, 3));

    for(int i = 0; i < 5; i++){
      erg += x[i];
    }
    return erg;
}

float aufgabe4verfahrenfloat(){

    //schriftlich = 0.0000317460317460317460317460317460317460

    float s = 0.0, sAlt = 0.0, d = 0.0;

    float x[5];
    x[0] = 10000.0;
    x[1] = ((-1.0 * pow(10, -3))/9.0);
    x[2] = (25.0 * pow(10, 2));
    x[3] = ((1.0 * pow(10, -3))/7.0);
    x[4] = (-12.5 * pow(10, 3));

    for(int i = 0; i < 5; i++){
        sAlt = s;
        s = s + x[i];
        d = d + (x[i]-(s-sAlt));
    }

    s = s+d;
    return s;
}

double aufgabe4verfahrendouble(){

    //schriftlich = 0.0000317460317460317460317460317460317460

    double s = 0.0,sAlt = 0.0, d = 0.0;

    double x[5];
    x[0] = 10000.0;
    x[1] = ((-1.0 * pow(10, -3))/9.0);
    x[2] = (25.0 * pow(10, 2));
    x[3] = ((1.0 * pow(10, -3))/7.0);
    x[4] = (-12.5 * pow(10, 3));

    for(int i = 0; i < 5; i++){
        sAlt = s;
        s = s + x[i];
        d = d + (x[i] - (s - sAlt));
    }

    s = s+d;

    return s;
}

void aufgabe4(){
    printf("schriftlich addiert:              0.0000317460317460317460317460317460317460\n");
    printf("normale addition float:           %f\n", aufgabe4float());
    printf("normale addition double:          %f\n", aufgabe4double());
    printf("verfahren aus der aufgabe float:  %f\n", aufgabe4verfahrenfloat());
    printf("verfahren aus der aufgabe double: %f\n", aufgabe4verfahrenfloat());
}

int main(void){
  aufgabe2();
  //aufgabe3();
  //aufgabe4();
  return 0;
}
