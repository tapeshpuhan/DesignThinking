#include <iostream>
#include "graph.hpp"
#include <string>

int main()
{
    Graph<std::string> sosial_nt_;
    
    sosial_nt_.AddVertex("A");
    sosial_nt_.AddVertex("B");
    sosial_nt_.AddEdge("A","B");
    return 0;
}
