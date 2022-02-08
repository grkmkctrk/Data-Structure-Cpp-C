#ifndef __nodeGraph_HPP__
#define __nodeGraph_HPP__

#include "edgeGraph.hpp"

template<class T>
class Node{
    public:
        size_t id;
        T data;

        std::list<Edge> edgeList;

        Node() : id(0), data(data){}
        Node(size_t id, T data) : id(id), data(data){}

        // to reach edges list of the node
        std::list<Edge> getEdgeList();
 
        // to get data
        size_t getId();

        // to get data
        T getData();

        // be careful with this function
        // id number show the position of the node in the vector
        void setId(size_t id);
        void setData(T data);
};

template<class T>
std::list<Edge> Node<T>::getEdgeList(){ 
    return edgeList; 
}

template<class T>
size_t Node<T>::getId(){ 
    return id; 
}

template<class T>
T Node<T>::getData(){ 
    return data; 
}

template<class T>
void Node<T>::setId(size_t id){ 
    this->id = id; 
}

template<class T>
void Node<T>::setData(T data){ 
    this->data = data; 
}

#endif