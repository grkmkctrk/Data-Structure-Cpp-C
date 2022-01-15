#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>
#include <string>

/*
    \\ What is stack?
    . Stack is a linear data structure.
    . It is a LIFO (Last In First Out) data structure.
    
    \\ How to use stack?
    . Push: add an element to the stack.
    . Pop: remove an element from the stack.
    . Peek: return the top element of the stack.
    . IsEmpty: check if the stack is empty.
    . IsFull: check if the stack is full.

    \\ How to implement stack?
    . Using linked list.

    \\ Visualization of stack
    
    . Stack: empty
    . push 1
    . Stack: null <- 1 <- top
    . push 2
    . Stack: null <- 1 <- 2 <- top
    . push 3
    . Stack: null <- 1 <- 2 <- 3 <- top
    . pop
    . Stack: null <- 1 <- 2 <- top
    . pop
    . Stack: null <- 1 <- top

*/

template<class T>
class stack{
private:
    class Node{
    friend class stack;
        T data;
        Node* prev;
    public:
        Node() : prev(nullptr), data(0){
            // std::cout << "Node()" << std::endl;
        }
        Node(T data) : prev(nullptr), data(data){
            // std::cout << "Node(T data)" << std::endl;
        }
        ~Node(){
            // std::cout << "~Node()" << std::endl;
        }
    };

    Node* top;

    int size;

public:

    stack() : top(nullptr), size(0){
        // std::cout << "stack()" << std::endl;
    }

    ~stack(){
        // std::cout << "~stack()" << std::endl;
    }

    void push(T data){
        Node* newNode = new Node(data);
        newNode->prev = top;
        top = newNode;
        size++;
    }

    void pop(){
        if(top == nullptr){
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* temp = top;  // store element to delete it later
        top = top->prev;      // unlinking the top element
        delete temp;          // deleting the element
        size--;
    }

    void print(){
        if(top == nullptr){
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* temp = top;        // store top to traverse the stack
        while(temp != nullptr){     // traverse the stack
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }

    T peek(){
        if(top == nullptr){
            std::cout << "Stack is empty." << std::endl;
            return 0;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    // bool isFull(){
        // i didn't add limit to the stack
        // so i can't check if the stack is full for now
        // i will add it later
    // }

};  
    
    

#endif
