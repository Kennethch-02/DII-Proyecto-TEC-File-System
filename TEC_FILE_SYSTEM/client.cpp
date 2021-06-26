#include "client.h"
/**
* \brief Cliente: Conecta con el servidor para completar el
* algoritmo Cliente-Servidor
* @param QTcpSocket
*/
client::client(qintptr handle, QObject *parent)
    :QTcpSocket(parent)
{
    setSocketDescriptor(handle);
    connect(this, &client::readyRead,[&](){
        emit AppReadyRead(this);
    });
    connect(this, &client::stateChanged, [&](int S){
        emit StateChanged(this, S);
    });
}
