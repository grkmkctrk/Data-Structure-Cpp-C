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
    void insertMax(T value);
    void swap(HeapNode *a, HeapNode *b);
    void sortIt(int8_t deep, uint64_t i);

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
    void remove();
    auto reachNode(uint8_t deep, uint64_t index);   
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
void Heap<T>::remove(){
    if(isEmpty()){
        std::cout << "Heap is empty" << std::endl;
        return;
    }else if(root->left == nullptr){
        root = nullptr;
        return;
    }else if(root->left != nullptr && root->right == nullptr){
        auto temp = root->left;
        temp->parent->left = nullptr;
        delete temp;
        inx--;
        return;
    }else if(depth > 1){
        if(inx == 1){
            auto lastNodeAdded = reachNode(depth - 1, pow(2, depth - 1));
            lastNodeAdded->parent->right = nullptr;
            delete lastNodeAdded;
            depth--;
            inx = pow(2, depth);
        }else{
            auto lastNodeAdded = reachNode(depth, inx - 1);
            if(inx - 1 % 2 == 0) lastNodeAdded->parent->right = nullptr;
            else lastNodeAdded->parent->left = nullptr;
            delete lastNodeAdded;
            inx--;
        }
    }
}

template<class T>
void Heap<T>::insert(T value){
    if(getType() == HeapType::MIN_HEAP){
        // std::cout << "Min" << std::endl;
        insertMin(value);
    }else if (getType() == HeapType::MAX_HEAP){
        insertMax(value);
        // std::cout << "Max" << std::endl;
    }else{
        std::cout << "Error" << std::endl;
        throw std::runtime_error("Heap type not supported");
    }
}

template<class T>
void Heap<T>::insertMax(T value){
    bool go = true;
    uint64_t tempInx = inx;
    uint8_t tempDepth = depth;
    HeapNode *curr = root;

    if(isEmpty()){
        root = new HeapNode(value);
        return;
    }

        while(go){
        if(curr->value >= value){
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
        }else{
            throw std::runtime_error("You can't insert a greater value than its parent value"); 
            return; 
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
        if(inx > 1) sortIt(depth, inx - 2);
        else sortIt(depth - 1, pow(2, depth - 1)-1);
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
        if(curr->value <= value){
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
        }else{
            throw std::runtime_error("You can't insert a less value than its parent value"); 
            return; 
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
        if(inx > 1) sortIt(depth, inx - 2);
        else sortIt(depth - 1, pow(2, depth - 1)-1);
    } 
}

template<class T>
void Heap<T>::sortIt(int8_t deep, uint64_t i){
    // go deep time left
    // HeapNode *curr = reachNode(deep, 1);
    bool sorted = false;

    while(!sorted){
        uint64_t howMany = 0;
        for(size_t index = 1; index <= i; index++){
            auto prev = (index == 1) ? nullptr : reachNode(deep, index-1);
            auto now = reachNode(deep, index);
            auto next = reachNode(deep, index + 1);

            if(prev != nullptr){
                if(now->value > next->value){
                    swap(now, next);
                    howMany++;
                }
                if(prev->value > now->value){
                    swap(prev, now);
                    howMany++;
                }
            }else if(prev == nullptr && now->value > next->value){
                swap(now, next);
                howMany++;
            }
            
        }
        if(howMany == 0) sorted = true;
    }

}

template<class T>
auto Heap<T>::reachNode(uint8_t deep, uint64_t index){
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
            size_t amountOfLeaf = (d == deptH && inx > 1) ? (inx - 1) : (pow(2, d));
            for(size_t leaf = 1; leaf <= amountOfLeaf/*pow(2, d)*/; leaf++){
                // std::cout << d << '-' << leaf << std::endl; 
                std::cout << reachNode(d, leaf)->value << " ";
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
