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

    Graph() {}

    Vertex* Add(char key)
    {
        Vertex *newVertex = new Vertex(key);
        vertices.Add(newVertex);

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

    void Dijkstra(Vertex*startVertex){
        //Initialize and fill Dijkstra Table
        LinkedList<DijkstraRecord> Table; //Init
        Vertex*graphVertex = vertices.BeginIteration();
        int unknownCnt=0;

        while(graphVertex!=NULL)
        {
            Table.Add(new DijkstraRecord(graphVertex,graphVertex==startVertex));
            graphVertex = vertices.GetNext();
            unknownCnt++;
        }
        // test 1

        while(unknownCnt>0)
        {
            //Find Lowest unkown vertex
            DijkstraRecord*LCRecord= Table.BeginIteration();
            DijkstraRecord*tableRecord = Table.BeginIteration();
            while(tableRecord!=NULL)
            {
                if(tableRecord->cost<LCRecord->cost && !tableRecord->known)
                    LCRecord = tableRecord;
                tableRecord = Table.GetNext();
            }
            LCRecord->known=true;
            graphVertex = LCRecord->vertx;
            unknownCnt--;

            Edge*edge = graphVertex->Edges.BeginIteration();

            while(edge!=NULL)
            {
                Vertex*childVertex = edge->Adjacent;
                float edgeWeight= edge->Weight;

                //find record of that child
                DijkstraRecord*childRecord = Table.BeginIteration();
                while(childRecord->vertx!=childVertex && childRecord->vertx!=NULL)
                    childRecord = Table.GetNext();

                //update its cost if lower
                //add graph vertex to record's path
                if(childRecord->cost>(edgeWeight+LCRecord->cost))
                {
                    childRecord->cost = (edgeWeight+LCRecord->cost);
                    childRecord->path = LCRecord;
                }

                //go to next child
                edge =  graphVertex->Edges.GetNext();
            }
        }
        DijkstraRecord*r= Table.BeginIteration();
        while(r!=NULL)
        {
            cout<< r->vertx->Key <<endl;
            cout<< r->cost << endl;
            cout<< r->known <<endl ;
            if(r->path!=NULL)
            cout<< r->path->vertx->Key<<endl;
            cout<<endl<<endl;
            r=Table.GetNext();
        }

    }
};

#endif // GRAPH_H

  /*    1---- Init Test
        DijkstraRecord *r = Table.BeginIteration();
        while(r!=NULL)
        {
            cout << r->vertx->Key << endl;
            cout << r->cost << endl;
            r=Table.GetNext();
        }*/
