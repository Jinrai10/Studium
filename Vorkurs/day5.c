#include<stdio.h>
#include"Header/arrayhelper.h"
#include<string.h>

void aufgabe2() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int arr2[] = {8, 0};
	int size = sizeof(arr)/sizeof(arr[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	printArray(arr, size);
	printf("%i\n", arrayInArray(arr2, arr, size2, size));
	moveArray(arr, 1, size);
	printArray(arr, size);
	switchArray(arr, size);
	printArray(arr, size);
	fillArray(arr, 1, size);
	printArray(arr, size);
}

int switchCharArray(char * arr, int size) {
	int j = size - 1;
	char p[size];
	int i;
	for(i = 0;i < (int) size/2;i++) {
		p[i] = arr[j];
		j--;
	}
	p[i] = '\0';
	return 0;
}

void aufgabe3() {
	char word[] = "giraf";
	char word1[10];
	int size = sizeof(word)/sizeof(word[0]);
	strncpy(word1, word, size);
	printf("%s\n", word);
	switchCharArray(word, size);
	printf("%s\n", word);
	if (strcmp(word1, word) == 0) {
		printf("Das wort ist ein Palindrom!\n");
	}
}

int main(){
	aufgabe2();
	aufgabe3();
	return 0;
}

