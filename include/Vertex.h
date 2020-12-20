#ifndef VERTEX_H
#define VERTEX_H

typedef class Vertex Vertex;

class Edge
{
public:
    Vertex *Adjacent;
    int Weight;

    Edge(Vertex *adjacent, int weight)
    {
        Adjacent = adjacent;
        Weight = weight;
    }
};

class Vertex
{
    public:
        char Key;
        int Visited;

        LinkedList<Edge> Edges;

        Vertex(char key)
        {
            Key = key;
            Visited = 0;
        }

        void AssignEdge(Vertex *adjacent, int weight)
        {
            Edge *edge = new Edge(adjacent, weight);
            Edges.Add(edge);
        }
};

#endif // VERTEX_H
