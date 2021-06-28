#include "controller_node.h"
#include "disknode.h"
#include <dirent.h>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QDir>
/**
* \brief Se encarga de parametrizar y desarrollar el manejo de los
* disknodes y su respectivas funciones.
* @param Class
*/
Controller_Node::Controller_Node()
{
    Head = new DiskNode(); //Crea el Head o cabeza de los Nodos
    add_node(); // lLama a la funcion AddNode para agregar los nodos restantes
    disk_pos = 1; //variable utilizada para la posicion del disco
    parity_pos = 5; //Establece el control de la paridad
}
/**
* \brief Establece el Head del controller Node
*/
void Controller_Node::set_head(DiskNode h)
{
    Head = &h;
}
/**
* \brief Retorna el Head del controller Node
*/
DiskNode Controller_Node::get_head()
{
    return *Head;
}
/**
* \brief Metodo encargado de añadir nodos al controller Node
*/
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
/**
* \brief Metodo encargado de escribir los valores
* entrantes en el RAID
*/
void Controller_Node::write_book(char *rute)
{
    QString rut = rute; //Se crea una copia de Rute
    if( DIR* pDIR = opendir(rute)){ //Instrucciones encargadar de abrir el Path del archivo
        while(dirent* entry = readdir(pDIR)){ //y cargar en una lista los elementos .txt
            QString fileName = entry->d_name;
            if( fileName != "." && fileName != ".." ){
                archivos.append(fileName);
            }
        }
        closedir(pDIR); // Cierra la carpeta,importante para mantener un manejo estricto de la memoria
    }
    for( QString& i : archivos){ //Recorre cada archivo .txt que encontrò
        QFile inputFile(rut+"/"+i); //Metodo para leer el archivo
        if (inputFile.open(QIODevice::ReadOnly))
        {
            QTextStream in(&inputFile);
            while (!in.atEnd()) //Intrucciones que se ejecuten hasta llegar al final del archivo txt
            {
                for (auto & b : in.readLine()){
                    QString Bytes = to_bytes(b);
                    bytes.clear();
                    for(int pos = 0; pos<4;pos++){ //Escribe los bytes en una variable, para hacer un sistema de dos pasos
                        bytes.append(Bytes[pos]);
                    }
                    write_in_disk();               //Posterior a eso, lo escribe en la memoria
                    bytes.clear();
                    for(int pos = 4; pos<8;pos++){
                        bytes.append(Bytes[pos]);
                    }
                    write_in_disk();
                }
            inputFile.close();
            }
        }
        QString Bytes = to_bytes("&"); //Establece un delimintante de forma que reconozca el cambio de libro
        bytes.clear();
        for(int pos = 0; pos<4;pos++){ //Mediante el sistema de dos pasos implementa la escritura
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
/**
* \brief Metodo encargado de leer la RAID y buscar en ella un
* elemento solicitado. Retorna (search archivo numero_de_caracter).
*/
QString Controller_Node::read_book(QString search)
{
    QStringList letter;                //Lista para cada char del Search
    QString delimiter = to_bytes("&"); // Recuerda el delimitante del libro
    QString result;                    //QString que almacena el resultado
    QString s_bit;                     // Almacena el valor en bits de cada Char
    QString word;                      //QString para reconstruir la palabra que se busca
    int book = 0;
    int parity = 5;
    int pos_letter = 0;
    int book_letter = 0;
    for (auto & b : search){
        QString bts = to_bytes(b);
        letter.append(bts);
    }
    DiskNode *node = Head; //Inicia por el Head del Controller
    for(int slt = 1; slt<Head->bits.size();slt++){ //Recorre cada Slot de la RAID
        for(int disk = 1; disk<6; disk++){         // y cada disco
            if(disk != parity){ //Instruccion cuando no se encuentra en el bit de paridad
                s_bit.append(QString::number(node->bits[slt-1]));
            }
            if(!node->is_last){ //avanza al siguiente nodo
                node = node->get_next();
            }
        }
        node = Head; // Restablece la posicion Head
        if(parity==1){ //Control de la paridad
            parity = 5;
        }else{
            parity--;
        }
        if(slt%2==0){ //Determina la lectura de un bit
            book_letter++; //Avanza en el caracter que se ha leido
            if(s_bit==delimiter){ //Confirma que el caracter leido no sea el delimitador
                book++;
                book_letter=0;
            }
            if(pos_letter<letter.size()){ //Confirma si ya termino de leer toda la palabra
                if(s_bit==letter[pos_letter]){
                    word.append(to_string(s_bit));
                    pos_letter++;
                }else{
                    word.clear();
                    pos_letter = 0;
                }
            }else{ //Si ya termino de leer toda la palabra procede armar el resultado
                QString _result = word+" "+archivos[book]+" "+QString::number(book_letter)+"\n";
                result.append(_result);
                pos_letter = 0;
                word.clear();
            }
            s_bit.clear();
        }
    }
    return result; //Return del resultado obtenido
}
/**
* \brief Metodo encargad de escribir en el disco, lo hace en conjuntos de bits
*/
void Controller_Node::write_in_disk()
{
    int _parity = 0; //Determina la paridad
    int this_bit; //se encarga de almacenar el bit que se quiere guardad
    for(int i = 0; i<bytes.size(); i++){ //Determina la paridad de los bites que se van a escribir
        this_bit = bytes[i].unicode()-48;
        if(this_bit==1){
            _parity += 1;
        }
    }
    DiskNode *node = Head; //Inicia por el Head del Controller
    int bit_pos = 0; //declara la pisicion del bit que se esta escribiendo
    for(int disk = 1; disk<6; disk++){
        this_bit = bytes[bit_pos].unicode()-48; //Usa la posicion para obtener el bit
        if(disk != parity_pos){ //Cuando no se encuentra en la paridad, escribe en el RAID
            node->bits.append(this_bit);
            bit_pos++;
        }else{ //Cuando no es asì, comprueba la paridad y la agrega
            if(_parity%2==0){
                node->bits.append(0);
            }else{
                node->bits.append(1);
            }
        }
        if(!node->is_last){ //Avanza en el DiskNode
            node = node->get_next();
        }
    }
    if(parity_pos==1){ //Controla la paridad segun la cantidad de Disk
        parity_pos=5;
    }else{
        parity_pos--;
    }

}
/**
* \brief Metodo encargado de convertir un string a bytes
*/
QString Controller_Node::to_bytes(QString str)
{
    QByteArray b = str.toUtf8().toHex(); //Combina UTF8 y Hexadecimal
    str.clear();
    for ( const auto& c : b  ){//Almacena los valores para posterior convertirlos a bytes
        str.append(c);
    }
    bool ok;
    QString binary = QString::number(str.toLongLong(&ok, 16),2); //Se convirten los valores a bits
    bool adjust = true;
    while(adjust){ //Se realiza un ajuste para que el sistema siempre tenga un largo de 8
        if(binary.size()<8){
            binary.insert(0,"0");
        }else{
            adjust = false;
        }
    }
    return binary;
}
/**
* \brief Metodo encargado de convertir a string los bits
* Basicamente es el proceso contrario del metodo to_bytes()
*/
QString Controller_Node::to_string(QString byte)
{
    bool ok;
    int iValue = byte.toInt(&ok, 2); //Obtinene el valor entero de los bits
    QString Hex = QString::number(iValue, 16); //calcula su valor Hexadecimal
    QString str = QString::fromUtf8(QByteArray::fromHex(Hex.toUtf8())); //realizada la interpretacion UTF8
    return str;
}
