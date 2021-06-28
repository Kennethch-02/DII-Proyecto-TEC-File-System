#include "node.h"


node::node() {
    this->right = NULL;
    this->left = NULL;
    this->next = NULL;
}

node::node(int val){
   this->value = val;
    this->right = NULL;
    this->left = NULL;
    this->next = NULL;

}

node::node(char dat, int val){
    this->data = dat;
    this->value = val;
    this->right = NULL;
    this->left = NULL;
    this->next = NULL;

}
