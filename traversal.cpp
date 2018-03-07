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

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<"DFS starting with node 2"<<endl;
    g.DFS(2);
    cout<<endl<<"BFS starting with node 2"<<endl;
    g.BFS(2);
}
