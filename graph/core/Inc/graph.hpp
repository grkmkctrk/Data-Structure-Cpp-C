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

        void addConenction(
            size_t source, T dataS, 
            size_t destination, T dataD,
            int weight){
            // create node with source and destination id
            // create edge between them
            Node<T> nodeSource = Node<T>(source, dataS);
            Node<T> nodeDestination = Node<T>(destination, dataD);
            Edge edge = Edge(destination, weight);

            nodeSource.edgeList.push_back(edge);
            nodes[source].push_back(nodeSource);
            // std::cout << sizeof(nodes) << std::endl;
            (nodes+destination)->push_back(nodeDestination);

        }

        // void print(){
        //     for(size_t i = 0; i < S; i++){
        //         std::cout << "Node: " << i << std::endl;
        //         for(auto node : nodes[i]){
        //             std::cout << "  " << node.getId() << std::endl;
        //         }
        //     }
        // }

        void print(){
            for(size_t i = 0; i <= nodes->size() ; i++){
                std::cout << "Node: " << i << std::endl;
                for(auto node : nodes[i]){
                    auto edgeList = node.getEdgeList();
                    for(auto edge : edgeList){
                        std::cout << "  " << edge.getDestination() << std::endl;
                    }
                }
            }
        }


        
};

#endif
