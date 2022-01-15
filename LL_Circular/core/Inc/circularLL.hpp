#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>

//======= Node class =======//
template<class T>
class Node{
    public:
        T data;
        Node *next;
    Node() : data(0), next(nullptr){
        //std::cout << "Node constructor called" << std::endl;
    }
    Node(T data) : data(data), next(nullptr){
        //std::cout << "Node copy constructor called" << std::endl;
    }
    ~Node(){
        //std::cout << "Node destructor called" << std::endl;
    }
};
//======= End Node class =======//


//======= Circular Linked List class =======//
template<class T>
class CircularLL : public Node<T>{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    CircularLL() : head(nullptr), tail(nullptr), size(0){
        //std::cout << "CircularLL default constructor called" << std::endl;
    }

    ~CircularLL(){
        //std::cout << "CircularLL destructor called" << std::endl;
    }

    void insertNode(T data){
        Node<T> *newNode = new Node<T>(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else{
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
        size++;
    }

    void sortedInsertNode(T data){
        Node<T> *newNode = new Node<T>(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else{
            Node<T> *temp = head;
            Node<T> *prev = nullptr;
            do{
                if(temp->data >= data){
                    if(temp == head){
                        head = newNode;
                        tail->next = newNode;                                                                                                                                                                                                                                                                                                                                                                                                                                                               
                        newNode->next = temp;
                        return;
                    }
                    prev->next = newNode;
                    newNode->next = temp;
                    return;
                }else{
                    prev = temp;
                    temp = temp->next;
                    if(prev == tail && temp == head){
                        prev->next = newNode;
                        newNode->next = head;
                        tail = newNode;
                    }
                }
            }while(temp != head);
            
        size++;
    }
}

    void printList(){
        Node<T> *temp = head;
        do{
            std::cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);
        std::cout << std::endl;
    }

    void deleteNode(int index){
        if(index < 0 || index >= size){
            std::cout << "Invalid index" << std::endl;
            return;
        }
        if(index == 0){         // if deleted node is head
            if(size == 1){      // and size is 1
                delete head;    // delete entire list
                head = nullptr;
                tail = nullptr;
            }
            else{               // if size is greater than 1
                Node<T> *temp = head; // store the head that will delete
                head = head->next;    // move head to next node
                tail->next = head;    // move tail to new head
                delete temp;          // detere node stored in temp which is head
            }
        }
        else{ // if deleted node is not head
            Node<T> *temp = head; // store head to temp to traverse
            for(int i = 0; i < index - 1; i++){ // search previous node with given index
                temp = temp->next;
            } 
            Node<T> *temp2 = temp->next; // store the node will be deleted
            temp->next = temp2->next;    // this is unlinking the node
            if(temp2 == tail){           // if deleted node is tail
                tail = temp;             // make tail to the previous node
            }
            delete temp2; // free deleted node's memory
        }
        size--;
    }

    void reverseList(){
        if(size == 0){
            return;
        }
        Node<T> *prev = nullptr;
        Node<T> *curr = head;
        Node<T> *next = head->next;
        while(next != head){ // it is mean when curr is not in tail
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        head = curr;
        tail = next;
        tail->next = head;
    }

    void sortList(){
        if(size == 0){
            return;
        }
        Node<T> *temp = head; // store head address to traverse
        while(temp != tail){  // traverse until tail
            Node<T> *temp2 = temp->next; // store next node address to traverse
            while(temp2 != tail){ //traverse until tail
                if(temp->data > temp2->data){ // check first temp node is greater than second temp node
                    T tempData = temp->data;  // if it is swap them
                    temp->data = temp2->data;
                    temp2->data = tempData;
                }
                temp2 = temp2->next; // otherwise move to next node
            }
            temp = temp->next; // out of inner loop move to next node
        }
    }
};

//======= End Circular Linked List class =======//

#endif
