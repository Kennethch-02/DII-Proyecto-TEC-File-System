#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "node.h"
class HuffTree
{
public:
    HuffTree();
    node head;

    int elements;
    void Insert(node*);

};

#endif // HUFFTREE_H
