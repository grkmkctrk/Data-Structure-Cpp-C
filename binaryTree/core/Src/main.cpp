#include "../Inc/binaryTree.hpp"

int main(){

    BinaryTree<int> tree;

    tree.insert(10);
    tree.insert(3);
    tree.insert(17);
    tree.insert(2);
    tree.insert(7);
    tree.insert(11);
    tree.insert(20);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(9);
    tree.insert(14);
    tree.insert(19);
    tree.insert(27);
 

    // tree.printNode(0, 1);
    // std::cout << std::endl;
    // tree.printNode(1, 1);
    // tree.printNode(1, 2);
    // std::cout << std::endl;
    // tree.printNode(2, 1);
    // tree.printNode(2, 2);
    // tree.printNode(2, 3);
    // tree.printNode(2, 4);
    // std::cout << std::endl;
    // tree.printNode(3, 1);
    // tree.printNode(3, 2);
    // tree.printNode(3, 3);
    // tree.printNode(3, 4);
    // tree.printNode(3, 5);
    // tree.printNode(3, 6);
    // tree.printNode(3, 7);
    // tree.printNode(3, 8);
    // std::cout << std::endl;

    // Will throw an exception
    // tree.printNode(0, 2);
    // tree.printNode(1, 3);
    // tree.printNode(2, 5);
    // tree.printNode(3, 9);

    tree.print(3);

    return 0;
}