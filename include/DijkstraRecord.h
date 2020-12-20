#ifndef DIJKSTRARECORD_H
#define DIJKSTRARECORD_H

#include <iostream>
#include "Vertex.h"

class DijkstraRecord
{
    public:
        Vertex *vertx;
        DijkstraRecord*path;
        bool known;
        float cost;

        DijkstraRecord(){}
        DijkstraRecord(Vertex*v,bool start=false){
            vertx = v;
            path= NULL;
            cost= start? 0:INT_MAX;
            known= false;
        }


    protected:

    private:
};

#endif // DIJKSTRARECORD_H
