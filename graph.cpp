#include "graph.h"
#include <queue>

using namespace std;

Graph::Graph(int v)
{
    this->vertices = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int source, int dest)
{
    adj[source].push_back(dest);
}

void Graph::performDFS(int source, bool visited[]) {
    visited[source] = true;
    cout<<source<<"\t";
    list<int>::iterator i;
    for (i=adj[source].begin(); i!=adj[source].end(); ++i) {
        if (!visited[*i]) {
            performDFS(*i, visited);
        }
    }
}

void Graph::DFS(int source)
{
    bool *visited = new bool[vertices];
    for (int i=0 ; i<vertices ; i++) {
        visited[i] = false;
    }
    cout<<endl;
    performDFS(source, visited);
    cout<<endl;

}

void Graph::BFS(int source) {
    queue<int> bfsQueue;
    list<int>::iterator i;
    bool visited[vertices];
    for (int i=0 ; i<vertices ; i++) {
        visited[i] = false;
    }
    bfsQueue.push(source);
    cout<<endl;
    while(!bfsQueue.empty()) {
        int front = bfsQueue.front();
        bfsQueue.pop();
        cout<<front<<"\t";
        visited[front] = true;
        list<int>::iterator j;
        for(j=adj[front].begin(); j!=adj[front].end(); ++j) {
            if (visited[*j] == false) {
                bfsQueue.push(*j);
            }
        }

    }
    cout<<endl;
}

void createGenericGraph(Graph g, bool cyclic) {
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    if (cyclic) {
        g.addEdge(2, 0);
    }
    g.addEdge(2, 3);
}

