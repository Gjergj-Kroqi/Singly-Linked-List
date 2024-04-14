#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* next;

} Node;

typedef struct list{

    int size;
    struct Node* tail;
    struct Node* head;

}List;

void initiList(List *l){
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

}

int isEmpty(List *l){
    return (l->head == NULL);
}

int add(List *l, Node *n){
    if(isEmpty(l)){
        l->head = n;
        l->tail = n;
        l->size = 1;
        
    }
    else {
        l->tail->next = n;
        l->tail = n;
        (l->size)++;
        if(l->size == 2){
           l->head->next = n;
        }
    }

    return 0;
}

int addAtPosition(List *l, Node *n, int position){
    Node* left = l->head;
    Node* right = l->head->next;




}

Node* get(List *l, int n){
    if(isEmpty(l)){
        return NULL;
    }

    Node *tmp;
    tmp = l->head;
    
    for(int i = 0; i < n; i++){
        tmp = tmp->next;
    }

    return tmp;
    
}
/*
int remove(List *l, Node *n){
    if(isEmpty(l)){
        return 1;
    }

    Node *tmp;
    tmp = l->head;

}*/

void clear(List *l){
    Node* current = l->head;
    Node* next;
    
    for(int i = 0; i < l->size; i++){
        next = current->next;
        free(current);
        current = next;
    }

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

}

int main(){

    List list;

    initiList(&list);

    Node node1;
    Node node2;
    Node node3;

    /*

    node1.data = 1;
    node2.data = 2;

    node1.next = &node2;

    printf("%d \n", node1.data);

    printf("%p \n", &node2);

    printf("%d", *node1.next);

    */

    add(&list, &node1);

    printf("Add of node1: %p \n", &node1);
    printf("Add of List head: %p \n", list.head);
    printf("Add of List tail: %p \n", list.tail);
    printf("List Size: %d \n \n", list.size);

    add(&list, &node2);

    printf("Add of List head: %p \n", list.head);
    printf("Add of Node2: %p \n", &node2);
    printf("Add of List tail: %p \n", list.tail);
    printf("List Size: %d \n \n", list.size);

    add(&list, &node3);

    printf("Add of List head: %p \n", list.head);
    printf("Add of Node3: %p \n", &node3);
    printf("Add of List tail: %p \n", list.tail);
    printf("List Size: %d \n \n", list.size);

    printf("Add of Node1.next: %p \n", node1.next);
    printf("Add of Node2: %p \n \n", &node2);

    printf("Add of Node2.next: %p \n", node2.next);
    printf("Add of Node3: %p \n\n", &node3);

    printf("Add of Node3: %p \n\n", get(&list, 2));


    printf("Add of Head.next: %p \n", list.head->next);
    printf("Add of Node2: %p \n\n", &node2);

    clear(&list);

    printf("%p \n", list.tail);

    printf("%p \n", list.head);


    return 0;
}


