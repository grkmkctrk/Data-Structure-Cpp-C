#include "../Inc/XORLL.h"

int main(){

    // create a new node
    Node* list = NULL;

    // insertion
    insert(&list, 21);
    insert(&list, 12);
    insert(&list, 32);
    insert(&list, 24);
    insert(&list, 53);
    insert(&list, 36);

    

    // print list
    print(list);


    return 0;
}