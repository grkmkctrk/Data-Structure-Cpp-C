#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>
#include <math.h>

std::string operator*(std::string const &s, std::size_t n);

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

    void deleteAndUnlink(Node* node){
        if(node->left == nullptr && node->right == nullptr){
            if(node->parent->left == node)
                node->parent->left = nullptr;
            else
                node->parent->right = nullptr;
            delete node;
        }else throw std::runtime_error("Node has children");
    }

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

    T remove(uint8_t depth, uint64_t index){
        if(root == nullptr)
            throw std::runtime_error("Tree is empty");
        
        uint64_t temp = index;
        Node *current = root;

        if(index > pow(2, depth))
            throw std::out_of_range("Index out of range");

        while(true){
            if(depth == 0)
                return current->data;

            else{
                if(depth == 1){
                    if(index % 2 == 0){

                        if(current->right != nullptr){
                            Node* temp = current->right;
                            deleteAndUnlink(current->right); // delete the bottom
                            return temp->data;
                        }
                        else 
                            throw std::runtime_error("This index is empty");
                        
                    }else{

                        if(current->left != nullptr){
                            Node* temp = current->left;
                            deleteAndUnlink(current->left); // delete the bottom
                            return temp->data;
                        }
                        else 
                            throw std::runtime_error("This index is empty");   

                    }
                }

                if(depth > 1){
                    uint16_t side = pow(2, depth)/2; // should i go left or right?
                    if(side < temp){
                        current = current->right;
                        temp = temp - side;
                    }
                    else current = current->left;
                    depth--;
                }
            }
        }
        throw "Nonsense proccess";
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
