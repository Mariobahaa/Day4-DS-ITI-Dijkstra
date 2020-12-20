#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include "Vertex.h"
#include "DijkstraRecord.h"

using namespace std;

class Graph
{
public:

    LinkedList<Vertex> vertices;
    int length;
    Graph() {length=0;}

    Vertex* Add(char key)
    {
        Vertex *newVertex = new Vertex(key);
        vertices.Add(newVertex);
        length++;

        return newVertex;
    }

    void AssignEdge(Vertex *frst, Vertex *scnd, int weight)
    {
        frst->AssignEdge(scnd, weight);
        scnd->AssignEdge(frst, weight);
    }

    void DepthFirst(Vertex *startVertex)
    {
        if(startVertex->Visited)
            return;

        cout << startVertex->Key << endl;
        startVertex->Visited  = 1;

        Edge *edge = startVertex->Edges.BeginIteration();

        while(edge != NULL)
        {
            DepthFirst(edge->Adjacent);

            edge = startVertex->Edges.GetNext();
        }
    }

    void Dijkstra(Vertex*start){
        //Initialize and fill Dijkstra Table
        LinkedList<DijkstraRecord> Table; //Init

        Vertex*graphVertex = vertices.BeginIteration();
        while(graphVertex!=NULL)
        {
            Table.Add(new DijkstraRecord(graphVertex,graphVertex==start));
            graphVertex = vertices.GetNext();
        }

        DijkstraRecord *r = Table.BeginIteration();
        while(r!=NULL)
        {
            cout << r->vertx->Key << endl;
            cout << r->cost << endl;
            r=Table.GetNext();
        }

    }
};

#endif // GRAPH_H
