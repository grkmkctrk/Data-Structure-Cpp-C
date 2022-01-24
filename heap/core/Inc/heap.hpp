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

    uint64_t inx = 1;
    uint8_t depth = 1;

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
    bool go = true;
    uint64_t tempInx = inx;
    uint8_t tempDepth = depth;
    HeapNode *curr = root;

    if(isEmpty()){
        root = new HeapNode(value);
        inx++;
        return;
    }

    while(go){

        if(tempDepth == 1){            
            if(inx % 2 == 0){
                if(curr->left == nullptr){
                    curr->left = new HeapNode(value, curr);
                    inx++;
                }
                go = false;
            }else{

                if(curr->left != nullptr)
                    std::cout << curr->left->data << " ";
                else std::cout << " ";
                
                go = false;
            }
            inx++;
            tempInx++;;
        }


        if(tempDepth > 1){
            uint16_t side = pow(2, tempDepth)/2; // should i go left or right?
            if(side < tempInx){
                curr = curr->right;
                tempInx = tempInx - side;
            }
            else curr = curr->left;
            tempDepth--;
        }

        if(inx > pow(2, depth)){
            depth++;
            inx = 1;
        }
    }
    tempInx = inx;
    tempDepth = depth;
}



template<class T>
void Heap<T>::swap(HeapNode *a, HeapNode *b){
    T temp = a->value;
    a->value = b->value;
    b->value = temp;
}

#endif
