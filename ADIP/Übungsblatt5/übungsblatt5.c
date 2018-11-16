#include <stdio.h>
#include <stdlib.h>

char * reverseString(char * str, int size){
    char * r = (char*)malloc(size * sizeof(char));
    for(int i = size - 1;i >= 0; i--) {
        r[size-i-1] = str[i];
    }
    printf("%s\n", r);
    return r;
}

int palindrom(char * str, int size) {
    int palindrom = 1;
    char * r = reverseString(str, size);
    for(int i = 0;i < size;i++) {
        if (r[i] != str[i]){
            printf("Das wort ist kein Palindrom!\n");
            return 0;
        }
    }
    printf("Das wort ist ein Palindrom!\n");
    return 1;
}

char * encrypt(char * s){
    char * r;
    int len = 0, tmp = 0;

    while(s[len] != '\0') len++;
    r = malloc(len * sizeof(char));

    for(int i = 0; i < len;i++){
        if((int) s[i] < 123 && (int) s[i] > 64)
            tmp = (((int) s[i]) + 13 - 65)%58 + 65;
        else
            tmp = s[i];
        r[i] = (char) tmp;
        printf("%c -> %c\n", s[i], r[i]);
    }

    return r;
}

char * decrypt(char * s){
    char * r;
    int len = 0, tmp = 0;

    while(s[len] != '\0') len++;
    r = malloc(len * sizeof(char));

    for(int i = 0; i < len;i++){
        if((int) s[i] < 123 && (int) s[i] > 64)
            tmp = (58 + ((int) s[i]) - 13 - 65)%58 + 65;
        else
            tmp = s[i];
        r[i] = (char) tmp;
        printf("%c -> %c\n", s[i], r[i]);
    }

    return r;
}

char * encryptbyk(char * s, int k){
    char * r;
    int len = 0, tmp = 0;

    while(s[len] != '\0') len++;
    r = malloc(len * sizeof(char));

    for(int i = 0; i < len;i++){
        if((int) s[i] < 123 && (int) s[i] > 64)
            tmp = (((int) s[i]) + k - 65)%58 + 65;
        else
            tmp = s[i];
        r[i] = (char) tmp;
        printf("%c -> %c\n", s[i], r[i]);
    }

    return r;
}

char * decryptbyk(char * s, int k){
    char * r;
    int len = 0, tmp = 0;

    while(s[len] != '\0') len++;
    r = malloc(len * sizeof(char));

    for(int i = 0; i < len;i++){
        if((int) s[i] < 123 && (int) s[i] > 64)
            tmp = (58 + ((int) s[i]) - k - 65)%58 + 65;
        else
            tmp = s[i];
        r[i] = (char) tmp;
        printf("%c -> %c\n", s[i], r[i]);
    }

    return r;
}

int main() {
    printf("Aufgabe1: \n");

    char * str = "Hello World";
    int size = 5, k;
    char * crypt;
    reverseString(str, size);
    palindrom(str, size);

    printf("Ceasar by 13\n");
    crypt = encrypt(str);
    printf("%s\n", crypt);
    printf("%s\n", decrypt(crypt));

    printf("Ceasar by k\n");
    k = 12;
    crypt = encryptbyk(str, k);
    printf("%s\n", crypt);
    printf("%s\n", decryptbyk(crypt, k));

    printf("Aufgabe2: \n");



    return 0;
}
