#include <iostream>
#include <string>
#include "HuffTree.h"
#include "huffcoder.h"

using  namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
/*
    HuffTree tree;
    tree.Insert(new node('b',4));
    tree.Insert(new node('c',2));
    tree.Insert(new node('d',1));
    tree.Insert(new node('a',3));


    node* itr = tree.head->next;
    for(int i = 0 ; i<tree.elements; i++){
        cout<<itr->value<<endl;
        itr = itr->next;

    }

    tree.Estructure_Tree();




    tree.printInorder();
*/

    huffcoder coder;

    string m = "j";

    string texto_codificado = coder.encode("Hola Mundo");
    cout<<texto_codificado<<endl;


    string texto_decodificado = coder.decode(texto_codificado);

    cout<<texto_decodificado<<endl;

    return 0;
}
