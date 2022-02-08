#include "../Inc/Graph.hpp"

int main(){

    // Create a graph
    Graph<int> graph(5);


    /*
        [0] = 32
        [1] = 12
        [2] = 13
        [3] = 71
        [4] = 88

                 ----821-----
                 |          |
                 v          |
     [0]--321-->[1]--501-->[2]
      |          |         ^|
     739        619  -119-/ |
      |          |  /       |
      v          v /        |
     [3]--772-->[4]<---230---
    
    */



    // Add nodes
    graph.addNode(0, 31);
    graph.addNode(1, 19);
    graph.addNode(2, 13);
    graph.addNode(3, 71);
    graph.addNode(4, 88);

    // Add edges
    graph.connect(0, 1, 321);
    graph.connect(0, 3, 739);
    graph.connect(1, 2, 501);
    graph.connect(1, 4, 619);
    graph.connect(2, 1, 821);
    graph.connect(2, 4, 230);
    graph.connect(3, 4, 772);
    graph.connect(4, 2, 110);


    graph.print();

    return 0;
}