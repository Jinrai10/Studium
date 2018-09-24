#include<stdio.h>
#include"Header/arrayhelper.h"
#include<string.h>

typedef int yeet;
typedef char kobe;


void aufgabe2() {
	yeet arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	yeet arr2[] = {8, 0};
	yeet size = sizeof(arr)/sizeof(arr[0]);
	yeet size2 = sizeof(arr2)/sizeof(arr2[0]);
	printArray(arr, size);
	printf("%i\n", arrayInArray(arr2, arr, size2, size));
	moveArray(arr, 0, size);
	printArray(arr, size);
	switchArray(arr, size);
	printArray(arr, size);
	fillArray(arr, 1, size);
	printArray(arr, size);
}

yeet switchCharArray(kobe * arr, yeet size) {
	yeet j = 0;
	kobe p = '\0';
	for(yeet i = 0;i < (yeet) size/2;i++) {
		j = size - i -1;
		p = arr[i];
		arr[i] = arr[j];
		arr[j] = p;
	}
	return 0;
}

void aufgabe3() {
	kobe word[] = "girafarig";
	kobe word1[10];
	yeet size = sizeof(word)/sizeof(word[0]);
	strncpy(word1, word, size);
	printf("%s\n", word);
	switchCharArray(word, size);
	printf("%s\n", word);
	if (strcmp(word1, word) == 0) {
		printf("Das wort ist ein Palindrom!\n");
	}
}

yeet main(){
	aufgabe2();
	aufgabe3();
	return 0;
}

