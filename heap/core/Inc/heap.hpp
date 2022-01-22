#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>
#include <math.h>

std::string operator*(std::string const &s, std::size_t n);
void print_list(std::string const &s, std::size_t n);

// Type of the heap
enum class HeapType{ // to reach from main created as global class
    MIN_HEAP,
    MAX_HEAP
};

// Heap class
template <typename T>
class Heap {
private:
    // Heap node class
    class HeapNode{
    private:
        friend class Heap<T>;
        T value;
        HeapNode *left;
        HeapNode *right;
        HeapNode *parent;
    public:
        HeapNode( // Constructor : (Adjusted as MinHeap as default)
            T value, HeapNode *parent = nullptr, HeapNode *left = nullptr, HeapNode *right = nullptr
            ) : value(value), left(left), right(right), parent(parent) 
            {}
        ~HeapNode(){
            delete this->left;
            delete this->right;
        }
    };

    // Heap root
    HeapNode *root;
    // Heap type
    HeapType type;

    // Insertion
    void insertMin(T value);
    void insertMax(T value);
    void swap(HeapNode *a, HeapNode *b);

public:
    // Constructor 
    Heap(HeapType type = HeapType::MIN_HEAP) : root(nullptr), type(type){}
    Heap(T value, HeapType type = HeapType::MIN_HEAP) : root(new HeapNode(value)), type(type) {}
    ~Heap();

    // Support functions
    bool isEmpty() const;      // both of these can not be changed
    HeapType getType() const;  

    // Heap operations
    void insert(T value);
    void remove(T value);
    void printNode();   
    void printHeap();
};


template<class T>
Heap<T>::~Heap(){
    delete this->root;
}

template<class T>
bool Heap<T>::isEmpty() const{
    return this->root == nullptr;
}

template<class T>
HeapType Heap<T>::getType() const{
    return this->type;
}

template<class T>
void Heap<T>::insert(T value){
    if(getType() == HeapType::MIN_HEAP){
        std::cout << "Min" << std::endl;
        insertMin(value);
    }else if (getType() == HeapType::MAX_HEAP){
        std::cout << "Max" << std::endl;
        insertMax(value);
    }else{
        std::cout << "Error" << std::endl;
        throw std::runtime_error("Heap type not supported");
    }
}

template<class T>
void Heap<T>::insertMin(T value){
    if(isEmpty()){
        this->root = new HeapNode(value);
        return value;
    }
    HeapNode *current = root;

    while(true){
        if(value > current->value){
            if(current->left == nullptr){
                current->left = new HeapNode(value, current);
                return;
            }else{
                // check for if current->left->value greater then value
                // if it is 
                // current->right = new HeapNode(value, current);
                // swap(current->left, current->right);
                // if it is not which means current->left->value is less then value
                // then current->right = new HeapNode(value, current);
            
            }
        }else{
            // WARNING Error
            throw std::logic_error("value can not be less than current->value");
        }
    }
}


template<class T>
void Heap<T>::swap(HeapNode *a, HeapNode *b){
    T temp = a->value;
    a->value = b->value;
    b->value = temp;
}

/*
void Heap<T>::insert(T value){
    HeapNode *newNode = new HeapNode(value);
    if(root == nullptr){
        root = newNode;
        return;
    }
    HeapNode *current = root;
    while(true){
        if(value < current->value){
            if(current->left == nullptr){
                current->left = newNode;
                newNode->parent = current;
                return;
            }
            current = current->left;
        }
        else{
            if(current->right == nullptr){
                current->right = newNode;
                newNode->parent = current;
                return;
            }
            current = current->right;
        }
    }
}
*/

#endif
