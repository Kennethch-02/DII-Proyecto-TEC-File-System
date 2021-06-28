#include "disknode.h"
#include "QDebug"
/**
* \brief Nodo perteneciente a Controller Node
* Cuenta con el almacenamiento de datos y de los punteros necesarios
* @param QList
*/
DiskNode::DiskNode()
{
    is_last = true; //Inicialmente se establece como el ultimo
}
/**
* \brief metodo que agrega bits a la lista
*/
void DiskNode::add_bit(int bit)
{
    bits.append(bit);
}
/**
* \brief metodo que retorna el bit en la posicion deseada
*/
int DiskNode::get_bit(int pos)
{
    return bits[pos];
}
/**
* \brief Metodo que retorna el Nodo Siguiente
*/
DiskNode *DiskNode::get_next()
{
    return next;
}
/**
* \brief Asigna el nodo siguiente
*/
void DiskNode::set_next(DiskNode *n)
{
    next = n;
}
