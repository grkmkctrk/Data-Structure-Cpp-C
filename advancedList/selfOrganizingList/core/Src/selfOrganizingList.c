#include "../Inc/selfOrganizingList.h"

// - initilaization
SOL_t* initSOL(kindOfSOL_t kindOfSOL){
    SOL_t* sol = (SOL_t*)malloc(sizeof(SOL_t));
    sol->head = initNode();
    sol->size = 0;
    sol->kindOfSOL = kindOfSOL;
    return sol;
}
// -


// - insertion
node_t* createNewNode(ui32 data){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSOL(SOL_t* sol, ui32 data){

    node_t* newNode =  createNewNode(data);
    insertAfter(&sol->head, data);
    sol->size++;
}
// -


// - print
void printSOL(SOL_t* sol){
    print(sol->head);
}
// -


// - delete
void deleteSOL(SOL_t* sol, ui32 data){
    deleteNode(&sol->head, data);
}
// -


// - search

node_t* find(node_t* head, node_t** prev, ui32 data){
    node_t* current = head;

    while(current != NULL){
        if(current->data == data){
            return current;
        }
        *prev = current;
        current = current->next;
    }
    return NULL;
}

void swap(node_t** a, node_t** b){
    ui32 temp = (*a)->data;
    (*a)->data = (*b)->data;
    (*b)->data = temp;

    temp = (*a)->search;
    (*a)->search = (*b)->search;
    (*b)->search = temp;
}

node_t* searchMTF(node_t* head, ui32 data){
    node_t* prev = NULL;
    node_t* found = find(head, &prev, data);
    if(found == NULL){
        return NULL;
    }else{
        swap(&found, &head);
        return head;
    }
}

node_t* searchTranspose(node_t* head, ui32 data){
    node_t* prev = NULL;
    node_t* found = find(head, &prev, data);
    if(found == NULL)
        return NULL;
    else{
        swap(&found, &prev);
        return prev;
    }

}

void printSearchSOL(SOL_t* sol){
    node_t* current = sol->head;
    while(current != NULL){
        printf("%d - %d\n", current->data, current->search);
        current = current->next;
    }
}

node_t* searchCount(node_t* head, ui32 data){ // memory massacre
    
    node_t* prev = NULL;
    node_t* found = find(head, &prev, data);
    found->search++;

    // sort the list depending on search count
    node_t* current = head;
    node_t* next = NULL;

    while(current != NULL){
        next = current->next;
        while(next != NULL){
            if(current->search < next->search){
                swap(&current, &next);
            }
            next = next->next;
        }
        current = current->next;
    }

    return head;
}

node_t* searchSOL(SOL_t* sol, ui32 data){
    switch(sol->kindOfSOL){
        case MTF:
            return searchMTF(sol->head, data);
        case Transpose:
            return searchTranspose(sol->head, data);
        case Count:
            return searchCount(sol->head, data);
        default:
            return NULL;
    }
}

// -