#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node* init(){
    node* head = NULL;
    return head;
}

int empty(node* head){
    if(head == NULL){
        return 1;
    }
    return 0;
}

node* push(node* head, int data){
    node* newHead = malloc(sizeof(node));
    newHead->next = head;
    newHead->data = data;

    return newHead;
}

int top(node* head){
    return head->data;
}

node* pop(node* head){
    node* new = head->next;
    free(head);
    return new;
}

void printStack(node* head){
    node* tmp = head;
    while(tmp != NULL){
        printf("[%i]", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(){
    node* head = init();
    head = push(head, 1);
    head = push(head, 2);
    printStack(head);
    head = pop(head);
    printStack(head);
    head = push(head, 6);
    printf("%i\n", top(head));
    printStack(head);

    return 0;
}
