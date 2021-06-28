#include "controller_node.h"
#include "disknode.h"
#include <dirent.h>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QDir>

Controller_Node::Controller_Node()
{
    Head = new DiskNode();
    add_node();
    disk_pos = 1;
    parity_pos = 5;
}
void Controller_Node::set_head(DiskNode h)
{
    Head = &h;
}
DiskNode Controller_Node::get_head()
{
    return *Head;
}
void Controller_Node::add_node()
{
    DiskNode *p = Head;
    for(int a = 0; a<5;a++){
        bool add = true;
        while (add) {
            if(p->is_last){
                DiskNode *m = new DiskNode();
                p->set_next(m);
                p->is_last = false;
                p = p->get_next();
                p->is_last = true;
                add = false;
            }else{
                p = p->get_next();
            }
        }
    }
}
void Controller_Node::delete_node()
{

}
void Controller_Node::write_book(char *rute)
{
    QStringList archivos;
    QString rut = rute;
    if( DIR* pDIR = opendir(rute)){
        while(dirent* entry = readdir(pDIR)){
            QString fileName = entry->d_name;
            if( fileName != "." && fileName != ".." ){
                archivos.append(fileName);
            }
        }
        closedir(pDIR);
    }
    for( QString& i : archivos){
        QFile inputFile(rut+"/"+i);
        if (inputFile.open(QIODevice::ReadOnly))
        {
            QTextStream in(&inputFile);
            while (!in.atEnd())
            {
                for (auto & b : in.readLine()){
                    bytes = to_bytes(b);
                    write_in_disk();
                }
            inputFile.close();
            }
        }
    }

}
void Controller_Node::read_book()
{

}

void Controller_Node::show_matriz()
{
    DiskNode This_Node = *Head;
    for(int disk = 0; disk<5; disk++){

        if(This_Node.get_next() != nullptr){
            This_Node = *This_Node.get_next();
        }else{
            This_Node = *Head;
        }
    }
}

void Controller_Node::write_in_disk()
{
    QStringList a;
    int _parity = 0;
    bool adjust = true;
    while(adjust){
        if(bytes.size()<8){
            bytes.insert(0,"0");
        }else{
            adjust = false;
        }
    }
    //First midle of bytes
    int this_bit;
    for(int i = 0; i<(bytes.size()/2); i++){
        this_bit = bytes[i].unicode()-48;
        if(this_bit==1){
            _parity += 1;
        }
    }
    //qDebug()<<"parity 1 "<<_parity%2<< "Bytes " << bytes;
    DiskNode *This_Node = Head;
    int disk = 1;
    int pos = 0;
    for(int i = 0; i<(bytes.size()/2)+1; i++){
        this_bit = bytes[pos].unicode()-48;
        if(disk == parity_pos){
            if(_parity%2==0){
                This_Node->bits.append(0);
            }else{
                This_Node->bits.append(1);
            }
            if(parity_pos == 1){
                parity_pos = 5;
            }else{
                parity_pos--;
            }
        }else{
            This_Node->bits.append(this_bit);
            pos++;
        }
        if(!This_Node->is_last){
            This_Node = This_Node->get_next();
        }else{
            This_Node = Head;
        }

        if(disk==5){
            disk = 1;
        }
        disk++;
    }
    //Second midle of bytes
    _parity = 0;
    for(int i = 4; i<(bytes.size()); i++){
        this_bit = bytes[i].unicode()-48;
        if(this_bit==1){
            _parity += 1;
        }
    }
    This_Node = Head;
    disk = 1;
    pos = 0;
    for(int i = 4; i<bytes.size(); i++){
        this_bit = bytes[i].unicode()-48;
        if(disk == parity_pos){
            if(_parity%2==0){
                This_Node->bits.append(0);
            }else{
                This_Node->bits.append(1);
            }
            if(parity_pos == 1){
                parity_pos = 5;
            }else{
                parity_pos--;
            }
            i--;

        }else{
            This_Node->bits.append(this_bit);
            pos++;
        }
        if(!This_Node->is_last){
            This_Node= This_Node->get_next();
        }else{
            This_Node = Head;
        }
        if(disk==5){
            disk = 1;
        }else{
            disk++;
        }
    }


}
QString Controller_Node::to_bytes(QString str)
{
    QByteArray b = str.toUtf8().toHex();
    str.clear();
    for ( const auto& c : b  ){
        str.append(c);
    }
    bool ok;
    QString binary = QString::number(str.toLongLong(&ok, 16),2);
    return binary;
}
QString Controller_Node::to_string(QString byte)
{
    bool ok;
    int iValue = byte.toInt(&ok, 2);
    QString Hex = QString::number(iValue, 16);
    QString str = QString::fromUtf8(QByteArray::fromHex(Hex.toUtf8()));
    return str;
}
