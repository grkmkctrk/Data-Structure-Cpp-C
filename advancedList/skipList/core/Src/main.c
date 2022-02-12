#include "../Inc/main.h"
#include "../Inc/skipList.h"


int main(){

    // node_t* head = NULL;

    // insertBefore(&head, 32);
    // insertBefore(&head, 23);
    // insertBefore(&head, 11);
    // insertBefore(&head, 12);
    // insertBefore(&head, 71);
    // insertBefore(&head, 31);
    // insertBefore(&head, 41);

    // insertAfter(&head, 32);
    // insertAfter(&head, 23);
    // insertAfter(&head, 11);
    // insertAfter(&head, 12);
    // insertAfter(&head, 71);
    // insertAfter(&head, 31);
    // insertAfter(&head, 41);

    // print(head);
    // sort(&head, MIN);
    // print(head);
    // sort(&head, MAX);
    // print(head);


    // node_t* head = initNode();

    // insertAfter(&head, 13);
    // insertAfter(&head, 32);
    // insertAfter(&head, 23);

    // print(head);

    //================================================

    // skipList_t* list = initSkipList(2);

    // // addAfter(&list, 13);
    // // addAfter(&list, 32);
    // // addAfter(&list, 23);
    // // addAfter(&list, 11);
    // // addAfter(&list, 27);

    // addBefore(&list, 13);
    // addBefore(&list, 32);
    // addBefore(&list, 23);
    // addBefore(&list, 11);
    // addBefore(&list, 27);

    // printSL(list);
    // sortSL(&list, MIN);
    // printSL(list);
    // sortSL(&list, MAX);
    // printSL(list);

    //================================================

    skipList_t* list = initSkipList(4);

    // create list
    add(&list, 13);
    add(&list, 32);
    add(&list, 23);
    add(&list, 11);
    add(&list, 27);
    add(&list, 71);
    add(&list, 31);
    add(&list, 41);
    add(&list, 12);
    add(&list, 14);
    add(&list, 75);
    add(&list, 35);
    add(&list, 45);
    add(&list, 39);
    add(&list, 37);
    add(&list, 33);
    add(&list, 29);

    // create express layer
    expressLayer(&list);

    printSL(list);
    printExpSL(list);

    // for(int i = 0; i < 20; i++){
    //    find(list, i);
    // }
    // node_t* exa = find(list, 13); 
    // printf("%d\n", exa->data);


    return 0;
}