#include <iostream>

#include "Graph.h"

using namespace std;

int main()
{
    Graph graph;

    Vertex *A = graph.Add('A');
    Vertex *B = graph.Add('B');
    Vertex *C = graph.Add('C');
    Vertex *D = graph.Add('D');
    Vertex *E = graph.Add('E');

    graph.AssignEdge(A, B, 5);
    graph.AssignEdge(A, C, 2);
    graph.AssignEdge(A, D, 3);
    graph.AssignEdge(B, C, 1);
    graph.AssignEdge(E, B, 3);
    graph.AssignEdge(E, C, 2);

    //graph.DepthFirst(A);
    graph.Dijkstra(A);

    return 0;
}
