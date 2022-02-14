#include "../Inc/main.h"
#include "../Inc/node.h"


int main(){

    node_t* head = initNode();

    insertAfter(&head, 1);
    insertAfter(&head, 2);
    insertAfter(&head, 3);
    insertAfter(&head, 4);
    insertAfter(&head, 5);
    insertAfter(&head, 6);
    insertAfter(&head, 7);
    insertAfter(&head, 8);

    print(head);

   

    
    return 0;
}