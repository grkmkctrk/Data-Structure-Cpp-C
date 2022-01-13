#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <iostream>
 
#define processOK 1
#define processFailed 0

/*
// C type: struct node
struct Node {
    int data;
    struct Node* next;
};
*/

template<class T>
class Node {
public:
    T data;
    Node* next;
};

template<class T>
size_t sizeNodes(Node<T>* head){
    int size = 0;
    auto current = head;
    while(current != NULL){
        size++;
        current = current->next;
    }
    //std::cout << "Size of the nodes: " << size << std::endl;
    return size;
}

template<class T>
void PrintLL(Node<T>* head){
    auto current = head; // auto = Node<T>*
    
    for (
        ; 
        current != NULL; 
        std::cout << current->data << " ",
        current = current->next
        );
    std::cout << std::endl;

}

template<class T>
void pushBack(Node<T>** head, T data){
    /*
        Node<T>** is a pointer point to a pointer of Node<T>
        The aim is to create a new node and assign it to the head pointer.
        We need to change the reference of the head pointer to the new node.
        Therefore we used pointer point to a pointer.
    */
    auto current = *head;
    auto newNode = new Node<T>();
    newNode->data = data;
    newNode->next = NULL;
    
    if(current == NULL){
        *head = newNode;
        return;
    }
    
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = newNode;
}

template<class T>
void pushFront(Node<T>** head, T data){
    /*
        Head should hold the address of the head pointer.
        We should create a newNode and data of newNode should be
        assigned to the data of the head and next of the newNode should be 
        assigned to the head.
        It is mean we have a new node and it point the first element of the nodes also
        it stores data in data.
    */ 
    auto newNode = new Node<T>();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

template<class T>
bool pushAfter(Node<T>** head, T data, int num){

    /*
        Find the node with the given number.
        Create a new node and assign the data to the new node.
        Assign the new node to the next of the node with the given number.
    */

    size_t size = sizeNodes(*head);
    if(num > size){
        std::cout << "The number is out of range.\n";
        return processFailed;
    }

    auto current = *head;
    auto newNode = new Node<T>();
    newNode->data = data;
    newNode->next = NULL;

    while(--num){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return processOK;
}

template<class T>
bool pushBefore(Node<T>** head, T data, int num){
    /*
        Find the node with the given number.
        Create a new node and assign the data to the new node.
        Assign the previous node to the newNode and newNode to the next of the node with the given number.
    */

    size_t size = sizeNodes(*head);
    if(num > size){
        std::cout << "The number is out of range.\n";
        return processFailed;
    }

    auto current = *head;
    Node<T>* prev = NULL;
    auto newNode = new Node<T>();
    newNode->data = data;
    newNode->next = NULL;

    if (current != NULL && num == 1){
        pushFront(head, data);
        return processOK;
    }

    while(--num){
        prev = current;
        current = current->next;
    }

    prev->next = newNode; 
    newNode->next = current;

    return processOK;
}

template<class T>
bool deleteNode(Node<T>** head, int num){
    size_t size = sizeNodes(*head);
    if(num > size){
        std::cout << "The number is out of range.\n";
        return processFailed;
    }

    Node<T>* temp = *head;
    Node<T>* previous = NULL;
    

    if (temp != NULL && num == 1){
        *head = temp->next;  // unlink the first node
        delete temp;         // delete the first node
        return processOK;
    }else{
        while(temp != NULL && --num){ // serching the node with the given number
            previous = temp;  
            temp = temp->next;
        }

        if(temp == NULL){
            return processFailed; // the node with the given number is not found
        }

        previous->next = temp->next; // unlink the node
        delete temp;                 // delete the node
    }
    return processOK;
}

template<class T>
void deleteList(Node<T>** head){
    Node<T>* current = *head;
    Node<T>* next = NULL;

    while(current != NULL){
        next = current->next; 
        delete current; // delete every node allocated in the list
        current = next;
    }
    *head = NULL; // no head reference
}

template<class T>
bool isThere(Node<T>* head, T data){
    auto current = head;
    while(current != NULL){ // go through the list
        if(current->data == data){ // if the data is found
            return processOK; // return true
        }
        current = current->next; 
    }
    return processFailed; // if not found return false
}

template<class T>
T search(Node<T>* head, size_t nth){
    auto current = head;
    
    size_t size = sizeNodes(head);
    if(nth > size){
        std::cout << "The number is out of range.\n";
        return static_cast<T>(INT16_MIN); // processFailed
    }
    
    while(--nth)  // go through the list
        current = current->next; // go to the next node

    return current->data; // return the node
}

template<class T>
void swapNodes(Node<T>** head, int num1, int num2){
    
    size_t size = sizeNodes(*head);
    if(num1 > size || num2 > size){
        std::cout << "The number is out of range.\n";
        return;
    }else if(num1 == num2){
        std::cout << "The numbers are the same.\n";
        return;
    }


    Node<T>* current1 = *head; 
    Node<T>* previous1 = NULL;

    Node<T>* current2 = *head;
    Node<T>* previous2 = NULL;
    
    Node<T>* temp = NULL;

    
    while(--num1){ // find the node with the first given number
        previous1 = current1;
        current1 = current1->next;
    }

    while(--num2){ // find the node with the second given number
        previous2 = current2;
        current2 = current2->next;
    }

    // if previous1 is NULL, it is mean *head is next of previous1
    if(previous1 == NULL) *head = current2; 
    else previous1->next = current2;
    
    // if previous2 is NULL, it is mean *head is next of previous2
    if(previous2 == NULL) *head = current1;
    else previous2->next = current1;

    temp = current1->next;  
    current1->next = current2->next;
    current2->next = temp;
}

template<class T>
void reverseNodes(Node<T>** head){
    Node<T>* current = *head;
    Node<T>* previous = NULL;
    Node<T>* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}

#endif
