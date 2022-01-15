#include "../Inc/circularLL.hpp"

int main(){

    CircularLL<int> cll;

    // std::cout << "inserting 1, 2, 3, 4" << std::endl;
    // cll.insertNode(4);
    // cll.insertNode(2);
    // cll.insertNode(1);
    // cll.insertNode(2);
    // cll.printList();

    // std::cout << "inserting 5, 6, 7, 8" << std::endl;
    // cll.insertNode(3);
    // cll.insertNode(5);
    // cll.insertNode(1);
    // cll.insertNode(3);
    // cll.printList();

    // std::cout << "delete node at index 2 and 3" << std::endl;
    // cll.deleteNode(2);
    // cll.deleteNode(3);
    // cll.printList();

    // std::cout << "reverse list" << std::endl;
    // cll.reverseList();
    // cll.printList();    

    // cll.sortList();
    // cll.printList();    

    cll.sortedInsertNode(1);
    cll.printList();
    cll.sortedInsertNode(7);
    cll.printList();
    cll.sortedInsertNode(4);
    cll.printList();
    cll.sortedInsertNode(4);
    cll.printList();
    cll.sortedInsertNode(2);
    cll.printList();
    cll.sortedInsertNode(6);
    cll.printList();
    cll.sortedInsertNode(6);
    cll.printList();
    cll.sortedInsertNode(3);
    cll.printList();
    cll.sortedInsertNode(5);
    cll.printList();
    cll.sortedInsertNode(0);
    cll.printList();
    cll.sortedInsertNode(0);
    cll.printList();



    return 0;
}