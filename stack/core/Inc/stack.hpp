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
    size_t size;
    size_t capacity;

public:

    stack() : top(nullptr), size(0), capacity(100){
        // std::cout << "stack()" << std::endl;
        // default capacity is 100
    }
    
    stack(size_t s) : top(nullptr), size(0), capacity(s){
        // std::cout << "stack(size_t s)" << std::endl;        
    }

    ~stack(){
        // std::cout << "~stack()" << std::endl;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    bool isFull(){
        return size == capacity;
    }

    void push(T data){
        if(isFull()){
            std::cout << "stack is full" << std::endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->prev = top;
        top = newNode;
        size++;
    }

    void pop(){
        if(isEmpty()){
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* temp = top;  // store element to delete it later
        top = top->prev;      // unlinking the top element
        delete temp;          // deleting the element
        size--;
    }

    size_t getSpace(){
        return capacity-size;
    }

    void print(){
        if(isEmpty()){
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
        if(isEmpty()){
            std::cout << "Stack is empty." << std::endl;
            return 0;
        }
        return top->data;
    }
    
    void reverse(){
        if(isEmpty()){
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* temp = top;
        Node* prev = nullptr;
        while(temp != nullptr){
            Node* next = temp->prev;
            temp->prev = prev;
            prev = temp;
            temp = next;
        }
        top = prev;    
    }

    T getNGE(int pos){
        if(isEmpty()){
            std::cout << "Stack is empty." << std::endl;
            return 0;
        }
        if(pos > size){
            std::cout << "Invalid position." << std::endl;
            return 0;
        }

        Node* temp = top;
        while(pos--){
            temp = temp->prev; // to find where traversing should start
        }

        Node* temp2 = temp;
        while(temp->prev != nullptr){ 
            temp = temp->prev;
            if(temp2->data < temp->data){
                return temp->data;
            }
            return -1;
        }
        return -1;
    }

    void prettyPrint(){
        if(isEmpty()){
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* temp = top;
        int index = 0;
        while(temp != nullptr){
            if(temp == top)
                std::cout << temp->data << " <-- top" << std::endl;
            else
                std::cout << temp->data << " <-- " << ++index << std::endl;
            std::cout << "|" << std::endl;
            std::cout << "v" << std::endl;
            temp = temp->prev;
        }
        std::cout << "nullptr" << std::endl;
    }

    void sort(){
        if(isEmpty()){
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* temp = top->prev;
        Node* next = top;
        while(temp->prev != nullptr){
            if(temp->data > temp->prev->data){
                T tempData = temp->data;
                temp->data = temp->prev->data;
                temp->prev->data = tempData;
                if(temp->data < next->data){
                    T tempData = temp->data;
                    temp->data = next->data;
                    next->data = tempData;
                }
            }
            next = temp;
            temp = temp->prev;
        }
    }

};  
    
    

#endif
