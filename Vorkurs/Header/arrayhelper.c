#include<stdio.h>
#include"arrayhelper.h"

int isvalueinarray(int val, int *arr, int size){
    for (int i=0; i < size; i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

int printArray(int * arr, int size) {
	for (int i = 0;i < size; i++) {
		printf("[%i]\t", arr[i]);
	}
	printf("\n");
	return 0;
}

int fillArray(int * arr, int n, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = n;
	}
	return 0;
}

int moveArray(int * arr, int n, int size) {
	int x = arr[size-1];
	for (int i = size-1; i >= 1; i--) {
		arr[i] = arr[i-1];
	}
	arr[0] = x;
	return 0;
}

int switchArray(int * arr, int size) {
	int j = 0;
	int p = 0;
	for(int i = 0;i < (int) size/2;i++) {
		j = size - i -1;
		p = arr[i];
		arr[i] = arr[j];
		arr[j] = p;
	}
	return 0;
}

int arrayInArray(int * arr, int * arr2, int n, int n2) {
	int start = isvalueinarray(arr[0], arr2, n2);
	int counter = start;
	
	if (start == -1 || start + n > n2) {
		return -1;
	}else {
		for (int i = 0; i < n;i++) {
			if (arr[i] == arr2[counter]) {
				counter++;
			}else {
				return -1;
			}	
		}
	}
	
	return start;
}
