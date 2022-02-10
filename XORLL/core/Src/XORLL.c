#include "../Inc/XORLL.h"

// npx finder
struct Node* npx(struct Node* f, struct Node* s){

    return (struct Node*)
            ((uintptr_t)f ^ (uintptr_t)s);;

}

// new list
List newList(List list){

    list = (List)malloc(sizeof(struct List));
    list->loc.head = NULL;
    list->loc.tail = NULL;
    return list;

}

// insert node
void insert(List* list, int data){
    
    // create a new node 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->npx = (*list)->loc.head;

    if((*list)->loc.head != NULL)
        (*list)->loc.head->npx = npx(newNode, (*list)->loc.head->npx);
    else
        (*list)->loc.tail = newNode;
    
    (*list)->loc.head = newNode;

}

// ptr next
void nexT(struct Node** curr, struct Node** prev, struct Node** next){
    
    while(*curr != NULL){
        printf("%d ", (*curr)->data);
        *next = npx((*curr)->npx, *prev);
        *prev = *curr;
        *curr = *next;
    }

}


// print list
void print(List list, print_t type){
    
    struct Node* prev = NULL;
    struct Node* next = NULL;

    if(type == pf){
        struct Node* curr = list->loc.head;
        nexT(&curr, &prev, &next);
    }else if(type == pb){
        struct Node* curr = list->loc.tail;
        nexT(&curr, &prev, &next);
    }printf("\n");

}
