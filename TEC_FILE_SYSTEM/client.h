#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
/**
* \brief Cliente: Conecta con el servidor para completar el
* algoritmo Cliente-Servidor
* @param QTcpSocket
*/
class client : public QTcpSocket
{
    Q_OBJECT
public:
    client(qintptr handle, QObject *parent = nullptr);
signals:
    void AppReadyRead(client *);
    void StateChanged(client *, int);
};

#endif // CLIENT_H
