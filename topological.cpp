#include<iostream>
#include "graph.h"
using namespace std;


int main()
{
    Graph g(4);
    /* Directed acyclic graph */
    createGenericGraph(g, false, true);
    g.topologicalSort();
}
