#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>
#include <list>
#include <vector>

/*
    / GRAPH
    . Graph structer include a list of nodes and a list of edges.
    . Each node has a name and a list of edges.
    . Each edge has a name and a list of nodes.


    / Representation of a graph
    . Adjancency Matrix:
        - A matrix of size n x n, where n is the number of nodes.
        - Each cell represents an edge between two nodes.
        - If the cell is 1, then there is an edge between the two nodes.
        - If the cell is 0, then there is no edge between the two nodes.
    . Adjacency List:
        - A list of lists.
        - Each list represents a node.
        - Each node has a list of edges.
        - Each edge has a list of nodes.

*/

/*
    [id: 12, name: "A"] ---[weight: 321]---> [id: 13, name: "B"]
    [id: 12, name: "A"] ---[weight: 123]---> [id: 14, name: "C"]

         12
         [A]
        /   \
      321   123
      /       \
     13       14
    [B]      [C]
*/


// edge
class Edge{
    public:
        size_t destination;
        int weight;
        
        Edge() : destination(0), weight(0){}
        
        Edge(size_t destination, int weight) : 
        destination(destination), weight(weight){}

        void setEdge(size_t destination, int weight){
            this->destination = destination;
            this->weight = weight;
        }

        void setDestination(size_t destination){ this->destination = destination; }

        void setWeight(int weight){ this->weight = weight; }

        size_t getDestination(){ return destination; }

        int getWeight(){ return weight; }

};

template<class T>
class Node{
    public:
        size_t id;
        T data;

        std::list<Edge> edgeList;

        Node() : id(0), data(data){}
        Node(size_t id, T data) : id(id), data(data){}

        std::list<Edge> getEdgeList(){ return edgeList; }
        size_t getId(){ return id; }
        T getData(){ return data; }
        void setId(size_t id){ this->id = id; }
        void setData(T data){ this->data = data; }
};


// graph class
template<class T>
class Graph{

    public:
        std::vector<Node<T>>* nodes;
        size_t S;

        Graph() : nodes(nullptr), S(0){} // do not use this constructor
        Graph(size_t size) : S(size){
            nodes = new std::vector<Node<T>>[S];
        }
        ~Graph(){
            delete[] nodes;
        }
    

        // to recreate node use same id
        void addNode(size_t id, T data){
            if(nodes[id].begin() != nodes[id].end()){ std::cout << "Node already exists" << std::endl; }
            else{ nodes[id].push_back(Node<T>(id, data)); }
            
            // Node<T> it = *nodes[id].begin();
            // size_t datas = it.getData();
            // std::cout << datas << std::endl;
        }

        // to recreate edge use same id
        void connect(size_t source, size_t destination, int weight){
            if(nodes[source].begin() == nodes[source].end()){ std::cout << "Source node does not exist" << std::endl; }
            else if(nodes[destination].begin() == nodes[destination].end()){ std::cout << "Destination node does not exist" << std::endl; }
            else{ nodes[source].begin()->edgeList.push_back(Edge(destination, weight)); }
        }

        void print(){
            for(size_t i = 0; i < S; i++){
                for(auto it = nodes[i].begin(); it != nodes[i].end(); it++){
                    std::cout << "Node(id:"<< it->getId() << ", data:" << it->getData() << ") has conenction to\n";
                    for(auto it2 = it->edgeList.begin(); it2 != it->edgeList.end(); it2++){
                        std::cout << "->Node(id:"<< it2->getDestination() << ") with weight:" << it2->getWeight() << std::endl;
                    }std::cout << std::endl;
                }
            }
        }


};

#endif
