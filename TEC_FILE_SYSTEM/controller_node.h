#ifndef CONTROLLER_NODE_H
#define CONTROLLER_NODE_H
#include "disknode.h"
#include "thread_read.h"
#include "thread_write.h"
#include <map>
#include <QObject>

class Controller_Node
{
public:
    Controller_Node();
    void set_head(DiskNode h);
    DiskNode get_head();
    void add_node();
    void delete_node();
    void write_book(char *rute);
    void read_book();
    thread_read *T_Read;
    thread_write *T_Write;
    QString bytes;
private:
    QList<int> disks;
    QList<int> slts;
    void show_matriz();
    int disk_pos;
    int parity_pos;
    void write_in_disk();
    std::map<QString, int> Diccionario;
    DiskNode *Head;
    QString to_bytes(QString str);
    QString to_string(QString byte);
};

#endif // CONTROLLER_NODE_H
