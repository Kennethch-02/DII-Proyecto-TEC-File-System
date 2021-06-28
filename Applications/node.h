//
// Created by User on 28/6/2021.
//

#ifndef NEW_FOLDER_NODE_H
#define NEW_FOLDER_NODE_H
#include <string>
using namespace std;

class node {

public:
    node* right;
    node* left;
    node* next;


    string data;
    int value = 0;
    string code;
    node();
    node(int);
    node(string,int);


};


#endif //NEW_FOLDER_NODE_H
