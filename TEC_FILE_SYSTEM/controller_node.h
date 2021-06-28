#ifndef CONTROLLER_NODE_H
#define CONTROLLER_NODE_H
#include "disknode.h"
#include <map>
#include <QObject>

class Controller_Node
{
public:
    Controller_Node();
    void set_head(DiskNode h);
    DiskNode get_head();
    void add_node();
    void write_book(char *rute);
    QString read_book(QString search);
    QString bytes;
    QStringList archivos;
private:
    QList<int> disks;
    QList<int> slts;
    int disk_pos;
    int parity_pos;
    int _parity;
    void write_in_disk();
    std::map<QString, int> Diccionario;
    DiskNode *Head;
    QString to_bytes(QString str);
    QString to_string(QString byte);
};

#endif // CONTROLLER_NODE_H
