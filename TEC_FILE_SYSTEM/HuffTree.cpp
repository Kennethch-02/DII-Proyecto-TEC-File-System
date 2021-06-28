#include "HuffTree.h"

HuffTree::HuffTree(){
    this->elements = 0;

}

void HuffTree::Insert(node* newnode){
    node *iter = &(this->head);
    for(int i = 0 ; i< elements+1;i++){
        if (iter->next == NULL){
            iter->next = newnode;
            this->elements+=1;
            return;
        }else if (newnode->value < iter->next->value){
            newnode->next = iter->next;
            iter->next = newnode;
            this->elements+=1;
            return;
        }else{
            iter = iter->next;
        }
    }

}
