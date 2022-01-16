#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>
    
    /*
        \ What is Queue?
        . A queue is a linear data structure that contains the entities in the queue.
        . The entities in the queue are inserted at the rear and removed from the front.
        . This is a FIFO (First In First Out) data structure.

    */

std::string operator*(std::string const &s, std::size_t n);

enum class print_type {
    PRINT_STRAIGHT,
    PRINT_PRETTY
};

template<class T>
class Queue{
private:
    class Node{
    private:
        friend class Queue;
        T data;
        Node* next;
    public:
        Node() : data(T()), next(nullptr){
            // std::cout << "Node()" << std::endl;
        }
    
        Node(T data) : data(data), next(nullptr){
            // std::cout << "Node(T data)" << std::endl;
        }
    
        ~Node(){
            // std::cout << "~Node()" << std::endl;
        }
    };

    Node* front;
    Node* rear;
    size_t size;
    size_t capacity;
public:
    Queue() : front(nullptr), rear(nullptr), capacity(100), size(0){
        // std::cout << "Queue()" << std::endl;
        // default capacity is 100
    }
   
    Queue(int capacity) : front(nullptr), rear(nullptr), capacity(capacity), size(0){
        // std::cout << "Queue(int capacity)" << std::endl;
    }
   
    ~Queue(){
        // std::cout << "~Queue()" << std::endl;
    }
    
    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    void enqueue(T data){
        if(isFull()){
            std::cout << "Queue is full" << std::endl;
            return;
        }
        Node* newNode = new Node(data);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
   
    T dequeue(){
        if(isEmpty()){
            throw "Queue is empty";
        }
        T data = front->data; // hold data to return
        Node* temp = front;
        front = front->next;  // unlink front
        delete temp;          // front address is now nullptr
        size--;
        return data;
    }

    T getFront(){
        if(isEmpty()){
            throw "Queue is empty";
        }
        return front->data;
    }

    T getRear(){
        if(isEmpty()){
            throw "Queue is empty";
        }
        return rear->data;
    }

    int getSize(){
        return size;
    }

    int getCapacity(){
        return capacity;
    }

    void reverseQueue(){
        if(isEmpty()){
            throw "Queue is empty";
        }
        Node* prev = nullptr;
        Node* curr = front;
        Node* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        front = prev;
    }

    void print(print_type type){

        if(isEmpty()){
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        if(type == print_type::PRINT_STRAIGHT){
            Node* temp = front;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        else if(type == print_type::PRINT_PRETTY){
            Node* temp = front;
            while(temp != nullptr){
                std::cout << temp->data;
                if(temp == front) std::cout << "  <-- front \n";
                else if(temp->next == nullptr) std::cout << "  <-- rear\n";
                else std::cout << std::endl;
                std::cout << "|\n";
                std::cout << "v\n";
                temp = temp->next;
            }
            std::cout << "nullptr" << std::endl;
        }
    }
    void queueInfo(){
        std::cout << "Queue Info" << std::endl;
        std::cout << "Size: " << size << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
        std::cout << "Front: " << front->data << std::endl;
        std::cout << "Rear: " << rear->data << std::endl;
    }

};


#endif
