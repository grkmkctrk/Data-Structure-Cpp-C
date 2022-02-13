#ifndef __SKIPLIST_H_
#define __SKIPLIST_H_

#include "main.h"
#include "node.h"

typedef enum{
    MTF,
    Count,
    Transpose
}kindOfSOL_t;

typedef struct SOL_t{
    node_t* head;
    ui32 size;
    kindOfSOL_t kindOfSOL;
}SOL_t;

// initilization
SOL_t* initSOL(kindOfSOL_t);

// insertion
void insertSOL(SOL_t*, ui32);

// print
void printSOL(SOL_t*);

// delete
void deleteSOL(SOL_t*, ui32);

// search
node_t* searchSOL(SOL_t*, ui32);
void printSearchSOL(SOL_t*);

#endif // __SKIPLIST_H_