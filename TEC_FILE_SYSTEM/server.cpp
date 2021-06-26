#include "server.h"
#include "client.h"
#include <QLocalSocket>
#include <QTextStream>
#include <QDebug>
#include <QMap>
#include "string"
#include <sstream>
/**
* \brief Servidor con las partes encargadas para la realizacion correcta de la interpretacion
* de los mensajes recibidos o enviados.
* @param QTcpServer()
*/
void server::emit_signal()
{
    emit cmd_change();
}

server::server(QObject *parent)
    :QTcpServer(parent)
{
}
bool server::startServer(quint16 port){
    return listen(QHostAddress::Any, port);
}
/**
* \brief Realiza las acciones segun los mensajes
* que recibe el servidor
* @param QTcpSocket
*/
void server::Do_Action(){
    //Acciones que realiza el servidor cuando recive un mensaje
    //Asignado al QString Received_Message
}
/**
* \brief Envia mensajes a cada socket conectado al servidor.
*/
void server::Send_Message(QString message){
    for(auto a : mSockets){ //Para cada cliente conectado
        CMD.append(">Servidor: Enviando Mensajes");
        emit_signal();
        QTextStream M(a); //Crea el QTextStream
        M<<message; //Envio de mensajes
        a->flush(); //Limpia el servidor
    }
}
/**
* \brief Señal protegida del Server, se ejecuta cuando hay un
* nuevo cliente
*/
void server::incomingConnection(qintptr handle){
    CMD.append(">Se ha conectado:" + handle); //Notifica en consola el cliente que se conecto
    emit_signal();
    auto socket = new client(handle, this); //Crea el cliente
    mSockets << socket; //Agrega el cliente a la lista de clientes
    connect(socket, &client::AppReadyRead, [&](client *S){ //Crea una coneccion con la señal para recibir mensajes
        //Recepcion de Mensajes
        QTextStream T(S); //Obtiene el QTextStream
        auto text = T.readAll(); //Lee el QString que contiene el mensaje
        Received_Message = text; //Asigna el mensaje a la variable Received_Message
        Do_Action(); //Llama a la funcion que interpretara el mensaje
    });
    connect(socket, &client::StateChanged, [&](client *S, int ST){ //Crea la señal de desconecciòn
        if (ST == QTcpSocket::UnconnectedState){ //Si un cliente se desconecta
            qDebug()<<"UnconnectedState: "<<S->socketDescriptor(); //Notifica en consola la desconeccion
            mSockets.removeOne(S); //remueve al cliente de la lista
        }
    });
}
