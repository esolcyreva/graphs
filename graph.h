#include <iostream>
#include <list>
using namespace std;

class Graph {
    int vertices;
    list<int> *adj;
    bool isCyclic(int source, bool visited[], bool recStack[]);

public:
    Graph(int v);

    void addEdge(int start, int end, bool directed);

    void BFS(int source);

    void DFS(int source);

    void performDFS(int source, bool visited[]);

    bool checkCyclic();

    void topologicalSort();

    void levelOrder(int source);
};

void createGenericGraph(Graph, bool, bool);
