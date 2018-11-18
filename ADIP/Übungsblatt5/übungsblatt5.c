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

char * encryptbyk(char * s, int k){
    char * r;
    k %= 52;
    int len = 0, tmp = 0;

    while(s[len] != '\0') len++;
    r = malloc(len * sizeof(char));

    for(int i = 0; i < len;i++){
        if((int) s[i] < 123 && (int) s[i] > 96){
            tmp = ((int) s[i] + k - 96);
            if(tmp > 26){
                tmp -= 26;
                if(tmp > 26){
                    tmp -= 26;
                    tmp += 96;
                }else tmp += 64;
            }else tmp += 96;
        }else if ((int) s[i] > 64 && (int) s[i] < 91){
            tmp = (int) s[i] + k - 64;
            if(tmp > 26){
                tmp -= 26;
                if(tmp > 26){
                    tmp -= 26;
                    tmp += 64;
                }else tmp += 96;
            }else tmp += 64;
        }else
            tmp = s[i];
        r[i] = (char) tmp;
        printf("%c -> %c\n", s[i], r[i]);
    }

    return r;
}

char * decryptbyk(char * s, int k){
    return encryptbyk(s, 52 - k);
}

char * encrypt(char * s){
    return encryptbyk(s, 13);
}

char * decrypt(char * s){
    return decryptbyk(s, 13);
}

int main() {
    printf("Aufgabe1: \n");

    char * str = "Hello WorldRSTU_";
    int size = 5, k;
    char * crypt;
    reverseString(str, size);
    palindrom(str, size);

    printf("Ceasar by 13\n");
    crypt = encrypt(str);
    printf("%s\n", crypt);
    printf("%s\n", decrypt(crypt));

    printf("Ceasar by k\n");
    k = 51;
    crypt = encryptbyk(str, k);
    printf("%s\n", crypt);
    printf("%s\n", encryptbyk(crypt, 52 - k));

    printf("Aufgabe2: \n");



    return 0;
}
