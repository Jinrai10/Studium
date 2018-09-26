#include"IntVector.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct IntVectorImpl{
	size_t capacity;
	size_t size;
	int *memory;
}IntVectorImpl;

IntVector IntVector_new(size_t capacity) {
	IntVectorImpl *vector = malloc(sizeof(IntVectorImpl));
	if (vector == NULL) return NULL;

	int *memory = malloc(capacity *sizeof(int));
	if (memory == NULL) {
		free(vector);
		return NULL;
	}

	vector->capacity = capacity;
	vector->size = 0;
	vector->memory = memory;
	return vector;
}

void IntVector_delete(IntVector vector) {
	free(vector->memory);
	free(vector);
}

int IntVector_push_back(IntVector vector, int value) {
	assert(vector != NULL && "Vector darf nicht NULL sein!\n");
	
	if (vector->capacity == vector-> size) {
		int * new_memory = realloc(vector->memory, vector->capacity*2);
		if (new_memory == NULL) return 1;
		vector->capacity *= 2;
		vector->memory = new_memory;
	}
	
	vector->memory[vector->size++] = value;
	
	return 0;
}

int IntVector_get(IntVector vector, size_t index) {
	assert(vector != NULL && "Vector darf nicht NULL sein!\n");
	
	return vector->memory[index];
}

void IntVector_set(IntVector vector, size_t index, int value) {
	assert(vector != NULL && "Vector darf nicht NULL sein!\n");
	vector->memory[index] = value;
}

size_t IntVector_size(IntVector vector) {
	assert(vector != NULL && "Vector darf nicht NULL sein!\n");
	
	return vector->size;
}

int main() {
	IntVector a = IntVector_new(10); 
	a->memory[0] = 2;
	printf("%i\n", a->memory[0]);
	IntVector_push_back(a, 3);
	IntVector_push_back(a, 4);
	IntVector_push_back(a, 5);
	for (int i = 0;i<10;i++) {
		printf("%i\n", IntVector_get(a, i));
	}
	return 0;
}
