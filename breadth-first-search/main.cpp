#include <iostream>
#include "graph.hpp"
#include "node.hpp"

int main() {
    Graph<int>* graph = new Graph<int>("\
    0 1 3\n\
    1 0 4\n\
    2 5 6\n\
    3 1 4\n\
    4 1 3\n\
    5 2 6\n\
    6 2 5\n\
    7 8\n\
    8 7");
    std::cout << graph->traverseToString();
    return 0;
}