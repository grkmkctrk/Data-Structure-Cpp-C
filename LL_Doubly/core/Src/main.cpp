#include "../Inc/doublyLL.hpp"

int main(){

    DoublyLL<int> dll;

    
    // dll.insertHead(1);
    // dll.insertHead(2);
    // dll.insertHead(3);
    // dll.insertHead(4);
    
    // std::cout << "print straitly" << std::endl;
    // dll.printLL(strait);

    // std::cout << "print reversely" << std::endl;
    // dll.printLL(reverse);

    // ===

    // dll.insertTail(1);
    // dll.insertTail(2);
    // dll.insertTail(3);
    // dll.insertTail(4);
    
    // std::cout << "print straitly" << std::endl;
    // dll.printLL(strait);

    // std::cout << "print reversely" << std::endl;
    // dll.printLL(reverse);

    // ===

    // dll.insertSorted(3);
    // dll.printLL(strait);
    // dll.insertSorted(4);
    // dll.printLL(strait);
    // dll.insertSorted(1);
    // dll.printLL(strait);
    // dll.insertSorted(2);
    // dll.printLL(strait);

    // dll.deleteNode(1);
    // dll.printLL(strait);

    // ===

    procces proc = procces::strait;

    dll.insertTail(3);
    dll.printLL(proc);
    dll.insertTail(4);
    dll.printLL(proc);
    dll.insertTail(1);
    dll.printLL(proc);
    dll.insertTail(2);
    dll.printLL(proc);

    dll.sortList();
    dll.printLL(proc);


    return 0;
}