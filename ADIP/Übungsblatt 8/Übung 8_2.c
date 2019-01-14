/* Komplexität:
insertFirst O(1), da durch den pointer auf head immer das erste element bekannt ist
insertLast O(n), da immer erst alle elemente zum ende durchgangen werden müssen
insertSorted O(n), da im worst case das element am ende eigefügt wird und somit wieder alle elemente durgangen werden
reverseListn O(n²), kleiner gauss

Mit end pointer
insertFirst O(1), //
insertLast O(1),  da direkt das letze element 
insertSorted O(n),
reverseListn O(n), da immer das letzte element direkt abgegriffen werden kann muss lediglich jedes element einmal durchgangen werden
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	int data;
}Node;

Node *push(Node *head,int pData) {
	if (head == NULL) {
		head = malloc(sizeof(Node));
		head->next = NULL;
		head->data = pData;
		return head;
	}
	Node *node = malloc(sizeof(Node));
	node->next = head;
	node->data = pData;
	return node;
}

int pop(Node **head) {
	int result = (*head)->data;
	Node* temp = (*head);
	(*head) = temp->next;
	free(temp);
	return result;
}

int peek(Node *head) {
	return head->data;
}

int isEmpty(Node *head) {
	return (head == NULL);
}

void print(Node *head) {
	Node *node = head;
	while (node != NULL) {
		printf("%i \n", node->data);
		node = node->next;
	}
}

int main() {
	Node *head = NULL;
	head = push(head, 4); 
	head = push(head, 2); 
	head = push(head, 1);
	
	printf("\n");

	printf("%i \n", peek(head));
	print(head);

	printf("\n");

	printf("%i \n", pop(head));
	print(head);

	printf("\n");

	printf("%i \n", isEmpty(head));
	printf("%i \n", pop(head));
	printf("%i \n", pop(head));

	printf("\n");

	printf("%i \n", isEmpty(head));
}
