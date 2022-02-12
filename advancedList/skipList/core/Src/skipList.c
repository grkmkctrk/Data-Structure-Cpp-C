#include "../Inc/skipList.h"

// begin initialize skipList
skipList_t* initSkipList(ui32 ratio){

    skipList_t* list = (skipList_t*)malloc(sizeof(skipList_t));
    list->head = NULL;
    list->headSL = NULL;
    list->size = 0;
    list->ratio = ratio;
    return list;

}
// end initialize skipList


// begin addion
void add(skipList_t** list, ui32 data){
        
        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        newNode->data = data;
        newNode->next = (*list)->head;
        insertBefore(&(*list)->head, data);
        sortSL(list, MIN);
        (*list)->size++;

}
// end addion


// begin print
void printSL(skipList_t* list){
    print(list->head);
}

void printExpSL(skipList_t* list){
    // print express layer
    expNode_t* temp = list->headSL;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }printf("\n");
}
// end print


// begin sort
void sortSL(skipList_t** list, sort_t sortType){
    sort(&(*list)->head, sortType);
}
// end sort


// begin express layer creation
void expressLayer(skipList_t** list){

    node_t* temp = (*list)->head;
    ui32 index = 0;

    while(temp != NULL){
        if(index % (*list)->ratio == 0){
            expNode_t* newNode = (expNode_t*)malloc(sizeof(expNode_t));
            newNode->data = temp->data;
            newNode->down = temp;
            newNode->next = NULL;

            if((*list)->headSL == NULL){
                (*list)->headSL = newNode;
            }
            else{
                expNode_t* tempExp = (*list)->headSL;
                while(tempExp->next != NULL){
                    tempExp = tempExp->next;
                }
                tempExp->next = newNode;
            }
        }
        temp = temp->next;
        index++;
    }

}
// end express layer creation

void throwError(char* error){
    printf("%s\n", error);
    exit(0);
}

// begin search
node_t* find(skipList_t* list, ui32 data){
    /*
    1. check if data of first express layer node is less than data (it shouldn't be)
    2. if it is then return NULL
    3. else, check if data of first express layer node is greater or equal data 
    4. if it is then search between these two nodes in node_t layer
    */

    expNode_t* temp = list->headSL;
    while(temp != NULL){
        if(data < temp->data){
            printf("the data is not in the list\n");
            return 0;
        }else if(data >= temp->data && data < temp->next->data){
            node_t* tempNode = temp->down;
            while(tempNode != temp->next->down){
                if(tempNode->data == data){
                    printf("%d is in the list\n", data);
                    return tempNode;
                }
                tempNode = tempNode->next;
            }
        }else{
            temp = temp->next;
        }
        printf("the data is not in the list\n");
        return 0;
    }

}
// end search
