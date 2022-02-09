#include "../Inc/XORLL.h"

// npx finder
Node* npx(Node* f, Node* s){
    // to use pointers in process use uintptr_t 
    return (Node*)((uintptr_t)f ^ (uintptr_t)s);
}

// insert node
void insert(Node** head, int data){
    /*
        addresses of the new node
        [ a | null^b.npx ] [ b | a.npx^c.npx ] [c | c.npx^null ]
    */ 
    
    // allocation
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->npx = *head;

    if(*head != NULL){
        // set the new node's npx to the old head's npx
        // newNode->npx->npx = npx(newNode, (*head)->npx);
        // or
        (*head)->npx = npx(newNode, (*head)->npx);
    }

    // set the head to the new node
    *head = newNode;

}

// print head
void print(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        printf("%d ", curr->data);
        next = npx(curr->npx, prev);
        prev = curr;
        curr = next;
    }printf("\n");
}