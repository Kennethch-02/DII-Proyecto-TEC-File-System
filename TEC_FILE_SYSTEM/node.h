#ifndef NODE_H
#define NODE_H
#include <string>;
using namespace std;

class node
{
public:
    node();
    node* right;
    node* left;
    node* next;


    char data;
    int value;
    string code;

    node(int);
    node(char,int);
};

#endif // NODE_H
