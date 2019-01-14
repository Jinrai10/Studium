#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort(int arr[], int length) {
	for (int i = 0; i < length-1; i++) {
		int klE = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[klE])
				klE = j;
		}
		swap(&arr[klE], &arr[i]);
	}
}

void insertionSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		int k = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > k) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}
}

void bubbleSort(int arr[], int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

int teilung(int arr[], int l, int h) {
	int pivot = arr[h];
	int i = (l - 1); 
	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return(i + 1);
}

void quickSort(int arr[], int l, int h) {
	if (l < h) {
		int t = teilung(arr, l, h);
		quickSort(arr, l, t - 1);
		quickSort(arr, t + 1, h);
	}
}


void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {	
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}



void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(){

	int arr1[100], arr2[100], arr3[100], arr4[100], arr5[100];
	srand(0);
	for (int i = 0; i < 100; i++) {
		arr1[i] = rand();
	}
	for (int i = 0; i < 100; i++) {
		arr2[i] = rand();
	}
	for (int i = 0; i < 100; i++) {
		arr3[i] = rand();
	}
	for (int i = 0; i < 100; i++) {
		arr4[i] = rand();
	}
	for (int i = 0; i < 100; i++) {
		arr5[i] = rand();
	}
	int length = sizeof(arr1) / sizeof(arr1[0]);

	printf("\n");
	printf("Selection");
	printf("\n");
	printArray(arr1, length);
	printf("\n");
	selectionSort(arr1, length);
	printArray(arr1, length);

	printf("\n");
	printf("Insertion");
	printf("\n");
	printArray(arr2, length);
	printf("\n");
	insertionSort(arr2, length);
	printArray(arr2, length);

	printf("\n");
	printf("Bubble");
	printf("\n");
	printArray(arr3, length);
	printf("\n");
	bubbleSort(arr3, length);
	printArray(arr3, length);

	printf("\n");
	printf("Quick");
	printf("\n");
	printArray(arr4, length);
	printf("\n");
	quickSort(arr4, 0, length - 1);
	printArray(arr4, length);

	
}