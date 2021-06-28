#ifndef DISKNODE_H
#define DISKNODE_H
#include <QList>
/**
* \brief Nodo perteneciente a Controller Node
* Cuentacon el almacenamiento de datos y de los punteros necesarios
* @param QList
*/
class DiskNode
{
public:
    DiskNode();
    void add_bit(int bit);
    int get_bit(int pos);
    DiskNode *get_next();
    void set_next(DiskNode *n);
    QList<int> bits;
    bool is_last;
private:
    DiskNode *next;
};
#endif // DISKNODE_H
