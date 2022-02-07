#include "../Inc/graph.hpp"

int main(){

    // Create a graph
    Graph<int> graph(2);


    // graph.addConenction(1, 2, 312);
    // graph.addConenction(1, 3, 511);
    // graph.addConenction(3, 1, 342);
    // graph.addConenction(4, 2, 651);
    // graph.addConenction(4, 1, 192);

    // Print the graph
    // graph.print();

    graph.addConenction(
        0, 31, 
        1, 51,
        421);

    graph.print();

    return 0;
}