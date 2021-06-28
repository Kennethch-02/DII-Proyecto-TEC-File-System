//
// Created by User on 28/6/2021.
//

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

node::node(string dat, int val){
    this->data = dat;
    this->value = val;
    this->right = NULL;
    this->left = NULL;
    this->next = NULL;

}