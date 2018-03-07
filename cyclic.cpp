
#include<iostream>
#include "graph.h"
using namespace std;


int main()
{
    Graph g(4);
    Graph h(4);
    createGenericGraph(g, true, true);
    createGenericGraph(g, false, true);
    cout<<"Checking if Graph g is cyclic"<<endl;
    if (g.checkCyclic()) {
        cout<<"Graph g is cyclic"<<endl;
    } else {
        cout<<"Graph g is not cyclic"<<endl;
    }
    cout<<"Checking if Graph h is cyclic"<<endl;
    if (h.checkCyclic()) {
        cout<<"Graph h is cyclic"<<endl;
    } else {
        cout<<"Graph h is not cyclic"<<endl;
    }
}
