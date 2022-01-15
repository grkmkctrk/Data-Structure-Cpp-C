#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>
#include <string>

enum class procces{
    strait,
    reverse
};

//======= Node class =======//

template<class T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node() : data(0), next(nullptr), prev(nullptr){
        // defaul constructer
        // std::cout << "Node()" << std::endl;
    };
    Node(T data) : data(data), next(nullptr), prev(nullptr){
        // constructer
        // std::cout << "Node(T data)" << std::endl;
    }
    ~Node(){
        // destructer
        // std::cout << "~Node()" << std::endl;
    }
};

//======= End Node class =======//

template<class T>
class DoublyLL : public Node<T>{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLL() : head(nullptr), tail(nullptr), size(0){
        // defaul constructer
        // std::cout << "DoublyLL()" << std::endl;
    }
    ~DoublyLL(){
        // destructer
        // std::cout << "~DoublyLL()" << std::endl;
    }

    void insertHead(T data){
        Node<T>* newNode = new Node<T>(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            newNode->next = nullptr;
            newNode->prev = nullptr;
        }
        else{
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertTail(T data){
        Node<T>* newNode = new Node<T>(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            newNode->next = nullptr;
            newNode->prev = nullptr;
        }
        else{
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertSorted(T data){
        Node<T>* newNode = new Node<T>(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            newNode->next = nullptr;
            newNode->prev = nullptr;
        }
        else{
            Node<T>* temp = head;
            while(temp != nullptr){
                if(temp->data > data){
                    if(temp->prev == nullptr){
                        newNode->next = temp;
                        newNode->prev = nullptr;
                        temp->prev = newNode;
                        head = newNode;
                        break;
                    }
                    else{
                        newNode->next = temp;
                        newNode->prev = temp->prev;
                        temp->prev->next = newNode;
                        temp->prev = newNode;
                        break;
                    }
                }
                else if(temp->next == nullptr){
                    temp->next = newNode;
                    newNode->prev = temp;
                    tail = newNode;
                    break;
                }
                else{
                    temp = temp->next;
                }
            }
        }
        size++;
    }

    void sortList(){
        if(head == nullptr){
            return;
        }
        else{
            Node<T>* temp = head;
            while(temp != tail){
                if(temp->data > temp->next->data){
                    if(temp->prev == nullptr){
                        T tempData = temp->data;
                        temp->data = temp->next->data;
                        temp->next->data = tempData;
                    }else if(temp->next != nullptr){
                        T tempData = temp->data;
                        temp->data = temp->next->data;
                        temp->next->data = tempData;
                        if(temp->prev->data > temp->data){
                            T tempData = temp->data;
                            temp->data = temp->prev->data;
                            temp->prev->data = tempData;
                        }
                    }
                    
                }else{
                    temp = temp->next;
                }
            }
        }
    }

    void printLL(enum procces proc){
        if(proc == procces::strait){
            Node<T>* temp = head;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
        }
        else if(proc == procces::reverse){
            Node<T>* temp = tail;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->prev;
            }
        }
        std::cout << std::endl;
    }

    void deleteNode(int index){
        if(index < 0 || index >= size){
            std::cout << "Index out of range" << std::endl;
            return;
        }
        if(index == 0){
            if(size == 1){
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else{
                // unlink head
                Node<T>* temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp; // we re doing it because we dont want old head allocate memory
            }
        }
        else if(index == size - 1){
            Node<T>* temp = tail; // store tail which will be deleted
            tail = tail->prev;
            tail->next = nullptr; // unlink tail and set previos node as tail
            delete temp; // let free old tail memory
        }
        else{
            Node<T>* temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        size--;
    }

};

//======= Circular Linked List class =======//

//======= End Circular Linked List class =======//

#endif
