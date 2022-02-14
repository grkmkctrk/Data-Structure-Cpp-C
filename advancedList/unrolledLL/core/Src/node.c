#include "../Inc/node.h"

static ui32 count = 0;

// begin initialization
node_t* initNode(){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node = NULL;
    return node;
}
// end initialization


node_t* createNode(ui32 size){

    if(size > MAXDATA){
        printf("Error: size of data is too large\n");
        return NULL;
    }

    node_t* node = (node_t*)malloc(sizeof(node_t));
    memset(node->data, 0, MAXDATA);
    node->sizeData = size;
    node->next = NULL;
    return node;
}


void insertAfter(node_t** head, ui32 data){
    
    if(count == 0){
        node_t* node = createNode(LIMIT);
        node->data[count] = data;
        count++;
        *head = node;
    }else{
        node_t* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(count == LIMIT){
            count = 0;
            node_t* node = createNode(LIMIT);
            node->data[count++] = data;
            temp->next = node;
        }else{
            temp->data[count++] = data;
        }
    }
}

void print(node_t* head){
    node_t* temp = head;
    while(temp != NULL){
        if(temp->next == NULL){
            for(ui32 i = 0; i < count; i++){
                printf("%d ", temp->data[i]);
            }
            printf("\n");
        }else{
            for(ui32 i = 0; i < temp->sizeData; i++){
                printf("%d ", temp->data[i]);
            }
            printf("\n");
        }
        temp = temp->next;

    }
}