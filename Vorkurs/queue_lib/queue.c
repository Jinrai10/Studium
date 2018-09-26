#include"queue.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef struct IntQueue{
	size_t size;
	int * memory;
}IntQueue;

IntQueue * IntQueue_new() {
	IntQueue *queue = (IntQueue*) malloc(sizeof(IntQueue));
	if (queue == NULL) return NULL;	

	int *memory = malloc(sizeof(int));
	if (memory == NULL) {
		free(queue);
		return NULL;
	}

	queue->size = 0;
	queue->memory = memory;
	return queue;
}

int IntQueue_enqueue(IntQueue *queue, int value) {
	assert(queue != NULL && "queue darf nicht null sein!");
	
	queue->memory = realloc(queue->memory, queue->size+1);
	
	queue->size++;
	queue->memory[queue->size-1] = value;
	
	return 0;
}

int IntQueue_dequeue(IntQueue *queue) {
	assert(queue != NULL && "queue darf nicht null sein!");
		
	int * new_memory = malloc(queue->size-1);
	
	for (int i = 0; i < sizeof(queue->memory)-2;i++) {
		new_memory[i] = queue->memory[i+1];
	}
	
	queue->memory = realloc(new_memory, queue->size--);
	
	return 0;
}

void IntQueue_delete(IntQueue *queue) {
	free(queue->memory);
	free(queue);
}

int IntQueue_empty(IntQueue *queue) {
	int * new_memory = calloc(0, 0);
	if (new_memory == NULL) return 1;
	queue->memory = new_memory;
	queue->size = 0;
	return 0;
}

int main() {
	IntQueue * queue = IntQueue_new();
	assert(queue != NULL && "queue darf nicht null sein!");
	IntQueue_enqueue(queue, 1);
	printf("%i\n", queue->memory[0]);
	IntQueue_enqueue(queue, 2);
	IntQueue_dequeue(queue);
	printf("%i\n", queue->memory[0]);
	IntQueue_empty(queue);
	printf("%i\n", queue->memory[1]);
	IntQueue_delete(queue);

	return 0;
}
