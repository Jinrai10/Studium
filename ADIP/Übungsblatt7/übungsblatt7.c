#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleNode{
    struct DoubleNode * next;
    double data;
} DoubleNode;

DoubleNode * insertFirst(DoubleNode * head, double data){
    DoubleNode * headNew = malloc(sizeof(DoubleNode));
    headNew->next = head;
    headNew->data = data;

    return headNew;
}

void printList(DoubleNode * head){
    DoubleNode * tmp = head;

    while(tmp != NULL){
        printf("[%lf]", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

DoubleNode * insertLast(DoubleNode * head, double data){
    DoubleNode * tmp = head;

    if(head==NULL){
        return insertFirst(NULL,data);
    }

    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = malloc(sizeof(DoubleNode));
    (tmp->next)->data = data;
    return head;
}

DoubleNode * reverseDoubleListCon(DoubleNode * head){
    DoubleNode * res;
    DoubleNode * tmp = head;

    while(tmp != NULL){
        res = insertFirst(res, tmp->data);
        tmp = tmp->next;
    }
    return res;
}

DoubleNode * reverseDoubleList(DoubleNode * head){
    DoubleNode * prev = NULL;
    DoubleNode * current = head, *next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

double get(DoubleNode * head, int i){
    DoubleNode * tmp = head;
    int t = 0;
    while(tmp->next != NULL && t < i){
        tmp = tmp->next;
        t++;
    }
    return tmp->data;
}

void delete(DoubleNode ** head, int i){
    DoubleNode * tmp = *head, *delEl;
    int t = 0;
    if(i == 0){
        delEl = *head;
        *head = (*head)->next;
        free(delEl);
        return;
    }

    while(tmp->next != NULL && t+1 < i){
        tmp = tmp->next;
        t++;
    }
    delEl = tmp->next;
    tmp->next = delEl->next;
    free(delEl);
}

DoubleNode * delete2(DoubleNode * head, int i){
    DoubleNode * tmp = head, *delEl;
    int t = 0;
    if(i == 0){
        DoubleNode * new = head->next;
        free(head);
        return new;
    }

    while(tmp->next != NULL && t+1 < i){
        tmp = tmp->next;
        t++;
    }
    delEl = tmp->next;
    tmp->next = delEl->next;
    free(delEl);
    return head;
}

void insert(DoubleNode ** head, int i, double data){
    if(i == 0) {
        *head = insertFirst(*head, data);
        return;
    }
    DoubleNode * newEl = malloc(sizeof(DoubleNode)), *tmp = *head;
    int t = 0;
    newEl->data = data;

    while(tmp->next != NULL && t+1 < i){
        tmp = tmp->next;
        t++;
    }
    newEl->next = tmp->next;
    tmp->next = newEl;
}

DoubleNode * insert2(DoubleNode * head, int i, double data){
    if(i == 0) {
        return insertFirst(head, data);
    }
    DoubleNode * newEl = malloc(sizeof(DoubleNode)), *tmp = head;
    int t = 0;
    newEl->data = data;

    while(tmp->next != NULL && t+1 < i){
        tmp = tmp->next;
        t++;
    }
    newEl->next = tmp->next;
    tmp->next = newEl;
    return head;
}




int main(){
    DoubleNode * head = insertFirst((DoubleNode *)NULL, 3.3);
    head = insertFirst(head, 5.98393);
    head = insertLast(head, 3.45345);
    head = insertLast(head, 333);

    printList(head);
    printList(reverseDoubleListCon(head));
    head = reverseDoubleList(head);
    printList(head);

    printf("%lf\n", get(head, 0));
    delete(&head, 1);
    printList(head);
    insert(&head, 1, 5.98393);
    printList(head);
    head = insert2(head, 1, 6);
    printList(head);
    head = delete2(head, 0);
    printList(head);

    return 0;
}
