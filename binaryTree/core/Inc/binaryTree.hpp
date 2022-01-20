#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>
#include <math.h>


template <class T>
class BinaryTree{
private:
    class Node{
    private:
        friend class BinaryTree;
        T data;
        Node *left;
        Node *right;
        Node *parent;
    public:
        Node(
            T data, Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr
            ):
            data(data), left(left), right(right), parent(parent){}
    };
    Node *root;
public:

    BinaryTree(): root(nullptr){}
    BinaryTree(T data): root(new Node(data)){}
    
    void insert(T data){
        if(root == nullptr){
            root = new Node(data);
            return;
        }
        Node *current = root;
        while(true){
            if(data < current->data){
                if(current->left == nullptr){
                    current->left = new Node(data, current);
                    return;
                }
                current = current->left;
            }
            else{
                if(current->right == nullptr){
                    current->right = new Node(data, current);
                    return;
                }
                current = current->right;
            }
        }
    }

    void printNode(uint8_t depth, uint64_t index){
        bool go = true;
        uint64_t temp = index;
        Node* curr = root;
        if(index > pow(2, depth)){
            throw std::out_of_range("Index out of range");
        }
        
        while(go){
            if(depth == 0){
                std::cout << curr->data;
                go = false;
            }else{
                if(depth == 1){            
                    if(index % 2 == 0){

                        if(curr->right != nullptr)
                            std::cout << curr->right->data << " ";
                        else std::cout << " ";
                        
                        go = false;
                    }else{

                        if(curr->left != nullptr)
                            std::cout << curr->left->data << " ";
                        else std::cout << " ";
                        
                        go = false;
                    }
                }
                if(depth > 1){
                    uint16_t side = pow(2, depth)/2; // should i go left or right?
                    if(side < temp){
                        curr = curr->right;
                        temp = temp - side;
                    }
                    else curr = curr->left;
                    depth--;
                }
            }

        }
    }

    void print(uint8_t depth){
        for(size_t d = 0; d < depth+1; d++){
            for (size_t leaf = 1; leaf < pow(2, d)+1; leaf++)
            {
                // std::cout << d << " " << leaf << '\n';
                printNode(d, leaf);
            }
            std::cout << '\n';
        }
    }

};



#endif
