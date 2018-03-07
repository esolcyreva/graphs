#include "graph.h"
#include <queue>
#include <vector>

using namespace std;

Graph::Graph(int v)
{
    this->vertices = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int source, int dest, bool directed)
{
    adj[source].push_back(dest);
    if (!directed) {
        adj[dest].push_back(source);
    }
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

bool Graph::isCyclic(int source, bool visited[], bool recStack[]) 
{
    list<int>::iterator i;
    visited[source] = true;
    recStack[source] = true;
    for(i=adj[source].begin(); i!=adj[source].end(); ++i) {
        if (!visited[*i] && isCyclic(*i, visited, recStack)) {
            return true;
        } 
        if (recStack[*i]) {
            return true;
        }
    }
    recStack[source] = false;
    return false;
}

bool Graph::checkCyclic()
{
    bool visited[vertices];
    bool recStack[vertices];
    for (int i=0 ; i<vertices ; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i=0 ; i<vertices ; i++) {
        if (isCyclic(i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

void createGenericGraph(Graph g, bool cyclic, bool directed) {
    g.addEdge(0, 1, directed);
    g.addEdge(0, 2, directed);
    if (cyclic) {
        g.addEdge(1, 2, directed);
        g.addEdge(2, 0, directed);
    }
    g.addEdge(2, 3, directed);
}


void Graph::topologicalSort()
{
    vector<int> deg(vertices,0);
    queue<int> vqueue;
    list<int> order;
    int count = 0;
    list<int>::iterator it;
    for (int v=0; v<vertices; v++) {
        list<int>::iterator i;
        for(i=adj[v].begin(); i!=adj[v].end(); ++i) {
            deg[*i]++;
        }
    }
    for (int v=0; v<vertices; v++) {
        if (!deg[v]) {
            vqueue.push(v);
        }
    }

    while(!vqueue.empty())
    {
        int v = vqueue.front();
        list<int>::iterator i;
        vqueue.pop();
        order.push_back(v);
        cout<<"Pushing = "<<v<<endl;
        for(i=adj[v].begin(); i!=adj[v].end(); ++i) {
            deg[*i]--;
            if (!deg[*i]) {
                vqueue.push(*i);
            }
        }
        count++;
    }
    cout<<"Topological Sort"<<endl;
    if (count!=vertices) {
        cout<<"There is a cycle in the graph"<<endl;
    }
    for (it=order.begin(); it!=order.end(); ++it) {
        cout<<*it<<"\t";
    }
    cout<<endl;
}


