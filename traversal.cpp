/*
 * Creating a graph with 4 vertices.
 * 0----->1
 *  ^->2</
 *     |
 *     |
 *     3
 */   


#include<iostream>
#include "graph.h"
using namespace std;


int main()
{
    Graph g(4);
    createGenericGraph(g, true, true);
    cout<<"DFS starting with node 2"<<endl;
    g.DFS(2);
    cout<<endl<<"BFS starting with node 2"<<endl;
    g.BFS(2);
}
