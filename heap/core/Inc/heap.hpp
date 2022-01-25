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
template <class T>
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
    // void insertMax(T value);
    void swap(HeapNode *a, HeapNode *b);
    void sortIt(int8_t deep);

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
    // void remove(T value);
    auto printNode(uint8_t deep, uint64_t index);   
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
        return;
    }

    
    while(go){
        if(tempDepth == 1){            
            if(inx % 2 == 0){
                if(curr->right == nullptr){
                    curr->right = new HeapNode(value, curr);
                }
                go = false;
            }else{

                if(curr->left == nullptr){
                    curr->left = new HeapNode(value, curr);
                }
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

    if(depth > 1){
        sortIt(depth-1);
    } 
}

template<class T>
void Heap<T>::sortIt(int8_t deep){
    // go deep time left
    // HeapNode *curr = printNode(deep, 1);

    for(size_t index = 1; index < pow(2, deep); index++){
        auto now = printNode(deep, index);
        auto next = printNode(deep, index+1);
        if(now->value > next->value){
            swap(now, next);
        }
    }


}

template<class T>
auto Heap<T>::printNode(uint8_t deep, uint64_t index){
    bool go = true;
    uint64_t tempIndex = index;
    HeapNode* curr = root;

    if(index > pow(2, deep)){
        std::cout << "Error" << std::endl;
        throw std::runtime_error("Index out of range");
    }else if(!deep){
        // return curr->value;
        return curr;
    }else{
        while(go){
        
            if(deep == 1){
                if(index % 2 == 0){
                    if(curr->right != nullptr){
                        // std::cout << curr->right->value << " ";
                        // return curr->right->value;
                        return curr->right;
                    }
                    go = false;
                }else{
                    if(curr->left != nullptr){
                        // std::cout << curr->left->value << " ";
                        // return curr->left->value;
                        return curr->left;
                    }
                    go = false;
                }
            }

            if(deep > 1){
                uint16_t side = pow(2, deep)/2; // should i go left or right?
                if(side < tempIndex){
                    curr = curr->right;
                    tempIndex = tempIndex - side;
                }
                else curr = curr->left;
                deep--;
            }
        }
    }
    return root;
}

template<class T>
void Heap<T>::printHeap(){

    if(isEmpty()){
        std::cout << "Empty" << std::endl;
        return;
    }else{
        uint8_t deptH = (inx == 1) ? (depth-1) : (depth);
        for(size_t d = 0; d <= deptH; d++){
            for(size_t leaf = 1; leaf <= pow(2, d); leaf++){
                // std::cout << d << '-' << inx << std::endl; 
                std::cout << printNode(d, leaf)->value << " ";
            }
            std::cout << std::endl;
        }
    }
}

template<class T>
void Heap<T>::swap(HeapNode *a, HeapNode *b){
    T temp = a->value;
    a->value = b->value;
    b->value = temp;
}


#endif
