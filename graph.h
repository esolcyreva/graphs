#include <iostream>
#include <list>
using namespace std;

class Graph {
    int vertices;
    list<int> *adj;

public:
    Graph(int v);

    void addEdge(int start, int end);

    void BFS(int source);

    void DFS(int source);

    void performDFS(int source, bool visited[]);

};

void createGenericGraph(Graph, bool);
