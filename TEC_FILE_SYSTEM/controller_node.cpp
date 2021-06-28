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
void Controller_Node::write_book(char *rute)
{
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
                    QString Bytes = to_bytes(b);
                    bytes.clear();
                    for(int pos = 0; pos<4;pos++){
                        bytes.append(Bytes[pos]);

                    }
                    write_in_disk();
                    bytes.clear();
                    for(int pos = 4; pos<8;pos++){
                        bytes.append(Bytes[pos]);
                    }
                    write_in_disk();
                }
            inputFile.close();
            }
        }
        QString Bytes = to_bytes("&");
        bytes.clear();
        for(int pos = 0; pos<4;pos++){
            bytes.append(Bytes[pos]);

        }
        write_in_disk();
        bytes.clear();
        for(int pos = 4; pos<8;pos++){
            bytes.append(Bytes[pos]);
        }
        write_in_disk();
    }
}
QString Controller_Node::read_book(QString search)
{
    QStringList letter;
    QString delimiter = to_bytes("&");
    QString result;
    QString s_bit;
    QString word;
    int book = 0;
    int parity = 5;
    int pos_letter = 0;
    int book_letter = 0;
    for (auto & b : search){
        QString bts = to_bytes(b);
        letter.append(bts);
    }
    DiskNode *node = Head;
    for(int slt = 1; slt<Head->bits.size();slt++){
        for(int disk = 1; disk<6; disk++){
            if(disk != parity){
                s_bit.append(QString::number(node->bits[slt-1]));
            }
            if(!node->is_last){
                node = node->get_next();
            }
        }
        node = Head;
        if(parity==1){
            parity = 5;
        }else{
            parity--;
        }
        if(slt%2==0){
            book_letter++;
            if(s_bit==delimiter){
                book++;
                book_letter=0;
            }
            if(pos_letter<letter.size()){
                if(s_bit==letter[pos_letter]){
                    word.append(to_string(s_bit));
                    pos_letter++;
                }else{
                    word.clear();
                    pos_letter = 0;
                }
            }else{
                QString _result = word+" "+archivos[book]+" "+QString::number(book_letter)+"\n";
                result.append(_result);
                pos_letter = 0;
                word.clear();
            }
            s_bit.clear();
        }
    }
    return result;
}
void Controller_Node::write_in_disk()
{
    int _parity = 0;
    int this_bit;
    for(int i = 0; i<bytes.size(); i++){
        this_bit = bytes[i].unicode()-48;
        if(this_bit==1){
            _parity += 1;
        }
    }
    DiskNode *node = Head;
    int bit_pos = 0;
    for(int disk = 1; disk<6; disk++){
        this_bit = bytes[bit_pos].unicode()-48;
        if(disk != parity_pos){
            node->bits.append(this_bit);
            bit_pos++;
        }else{
            if(_parity%2==0){
                node->bits.append(0);
            }else{
                node->bits.append(1);
            }
        }
        if(!node->is_last){
            node = node->get_next();
        }
    }
    if(parity_pos==1){
        parity_pos=5;
    }else{
        parity_pos--;
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
    bool adjust = true;
    while(adjust){
        if(binary.size()<8){
            binary.insert(0,"0");
        }else{
            adjust = false;
        }
    }
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
