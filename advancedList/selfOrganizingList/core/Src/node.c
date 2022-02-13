#include "../Inc/node.h"

// begin initialization
node_t* initNode(){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node = NULL;
    return node;
}
// end initialization


// begin insertion
void insertAfter(node_t** head, ui32 data){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->search = 0;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }
    else{
        node_t* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

}

void insertBefore(node_t** head, ui32 data){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->search = 0;
    newNode->next = *head;
    *head = newNode;
}
// end insertion


// begin deletion
void deleteNode(node_t** head, ui32 data){
    node_t* current = *head;
    node_t* prev = NULL;
    while(current != NULL){
        if(current->data == data){
            if(prev == NULL)
                *head = current->next;
            else
                prev->next = current->next;
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Data not found\n");
}
// end deletion


// begin print
void print(node_t* list){
    while(list != NULL){
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}
// end print


// begin sort
void sort(node_t** head, sort_t sortType){
    
    node_t* current = *head;
    node_t* next = NULL;
    
    ui32 tempData = 0;
    while(current != NULL){
        next = current->next;
        while(next != NULL){
            if(sortType == MIN){
                if(current->data > next->data){
                    tempData = current->data;
                    current->data = next->data;
                    next->data = tempData;
                }
            } else if(sortType == MAX){
                if(current->data < next->data){
                    tempData = current->data;
                    current->data = next->data;
                    next->data = tempData;
                }
            }
            next = next->next;
        }
        current = current->next;
    }
    
}
// end sort



