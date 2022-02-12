#ifndef __SKIPLIST_H_
#define __SKIPLIST_H_

#include "main.h"
#include "node.h"

typedef struct expNode_t {
    ui32 data;
    struct expNode_t* next;
    node_t* down;
} expNode_t;


typedef struct skipList_t {
    
    // current size of skipList
    ui32 size;  

    ui32 data;
    // linked list
    node_t* head; 
    // express layer
    expNode_t* headSL;   
    // ratio of express layer
    ui32 ratio;

} skipList_t;

// begin initialize skipList
skipList_t* initSkipList(ui32);
// end initialize skipList


// begin insertion
void add(skipList_t**, ui32);
// end insertion


// begin print
void printSL(skipList_t*);
void printExpSL(skipList_t*);
// end print


// begin sort
void sortSL(skipList_t**, sort_t);
// end sort

// begin express layer creation
/* be careful with this function, it will change the original skipList */
void expressLayer(skipList_t**);
// end express layer creation


// begin search
node_t* find(skipList_t*, ui32);
// end search

#endif // __SKIPLIST_H_