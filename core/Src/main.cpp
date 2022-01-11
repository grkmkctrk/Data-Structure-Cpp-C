#include "../Inc/linkedList.hpp"

int main()
{

    // Create a new node
    Node<int> *nodes = new Node<int>();

    // initialize the data
    nodes = NULL;

    // push back
    std::cout << "---- pushBack() ----\n";  
    pushBack(&nodes, 1); 
    PrintLL(nodes);
    pushBack(&nodes, 2); 
    PrintLL(nodes);
    pushBack(&nodes, 3); 
    PrintLL(nodes);

    std::cout << "---- pushFront() ----\n";  
    pushFront(&nodes, 0);
    PrintLL(nodes);
    pushFront(&nodes, -1);
    PrintLL(nodes);
    pushFront(&nodes, -2);
    PrintLL(nodes);

    std::cout << "---- pushAfter() ----\n";  
    pushAfter(&nodes, 3, 5);
    PrintLL(nodes);
    pushAfter(&nodes, 3, 2);
    PrintLL(nodes);
    pushAfter(&nodes, 3, 1);
    PrintLL(nodes);


    std::cout << "---- pushBefore() ----\n";  
    pushBefore(&nodes, 1, 5);
    PrintLL(nodes);
    pushBefore(&nodes, 1, 2);
    PrintLL(nodes);
    pushBefore(&nodes, 1, 1);
    PrintLL(nodes);


    std::cout << "---- deleteNode() ----\n";  
    deleteNode(&nodes, 3);
    PrintLL(nodes);
    deleteNode(&nodes, 4);
    PrintLL(nodes);
    deleteNode(&nodes, 6);
    PrintLL(nodes);

    // std::cout << "---- deleteList() ----\n";  
    // PrintLL(nodes);
    // deleteList(&nodes);
    // PrintLL(nodes);

    std::cout << "---- isThere() ----" << std::endl;
    std::cout << isThere(nodes, 2) << std::endl;

    std::cout << "---- search() ----" << std::endl;
    auto temp = search(nodes, 7);
    std::cout << "The data is: " << temp << std::endl;

    std::cout << "---- swapNodes() ----" << std::endl;
    swapNodes(&nodes, 1, 3);
    PrintLL(nodes);
    swapNodes(&nodes, 6, 1);
    PrintLL(nodes);

    return 0;
}