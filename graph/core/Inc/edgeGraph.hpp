#ifndef __edgeGraph_HPP__
#define __edgeGraph_HPP__

#include <iostream>
#include <list>
#include <vector>

// edge
class Edge{
    public:
        size_t destination;
        int weight;
        
        Edge() : destination(0), weight(0){}
        
        Edge(size_t destination, int weight) : 
        destination(destination), weight(weight){}

        // also instead initilize with destination and weight 
        // you can use this function
        void setEdge(size_t, int);        

        // to set destiantion node
        void setDestination(size_t);
        
        // to set weight
        void setWeight(int);

        // to get destination node
        size_t getDestination();

        // to get weight
        int getWeight();
        
};

void Edge::setEdge(size_t destination, int weight){
    this->destination = destination;
    this->weight = weight;
}

void Edge::setDestination(size_t destination){ 
    this->destination = destination; 
}

void Edge::setWeight(int weight){ 
    this->weight = weight; 
}

size_t Edge::getDestination(){ 
    return destination; 
}

int Edge::getWeight(){ 
    return weight; 
}




#endif