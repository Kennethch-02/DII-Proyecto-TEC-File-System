//
// Created by User on 28/6/2021.
//

#ifndef NEW_FOLDER_HUFFTREE_H
#define NEW_FOLDER_HUFFTREE_H

#include "node.h"
#include <iostream>

#include <vector>
using namespace std;

class HuffTree {
public:

    HuffTree();
    node *head;

    int elements;
    void Insert(node*);

    void Estructure_Tree();
     vector<string> codelist;
     vector<string> datalist;

    void printInorder();
    void printInorder(node* node,string code);


};


#endif //NEW_FOLDER_HUFFTREE_H
