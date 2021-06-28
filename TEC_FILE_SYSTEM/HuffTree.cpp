//
// Created by User on 28/6/2021.
//

#include "HuffTree.h"

HuffTree::HuffTree(){
    this->elements = 0;
    this->head = new node();
}
/**
 *
 *
 * Metodo para insertar nodo en arbol
 *
 * @param Caracter envuelto en un nodo al arbol.
 */
void HuffTree::Insert(node* newnode){
  //  cout<<newnode->value<<endl;
    node* iter = this->head;
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

/**
 *
 *
 * Metodo para estructurar el arbol como un heap
 *
 * @param
 */
void HuffTree::Estructure_Tree(){

    node *iter = this->head->next;


    node *newnode;
    while(this->elements>1){
        newnode = new node(iter->value + iter->next->value);
        newnode->left = iter;
        newnode->right= iter->next;
        this->Insert(newnode);
        iter = iter->next->next;
        this->head->next = iter;
        this->elements-=2;

    }


}
/**
 *
 *
 * metodo para definir el pero y el codigo de cada nodo hoja
 *
 * @param
 */

void HuffTree::printInorder(){
    return printInorder(this->head->next,"");
}

void HuffTree::printInorder(node *node, string code)
{
    if (node->left == NULL && node->right== NULL ) {
        cout<<node->data<<code<<endl;

        datalist.push_back(node->data);

        codelist.push_back(code);

        return;
    }
    /* first recur on left child */
    printInorder(node->left,code + '0');

    /* then print the data of node */


    /* now recur on right child */
    printInorder(node->right,code + '1');
}


