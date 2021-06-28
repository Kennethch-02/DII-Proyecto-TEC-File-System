#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QJsonDocument>
#include <QMap>
/**
* \brief Servidor con las partes encargadas para la realizacion correcta de la interpretacion
* de los mensajes recibidos o enviados.
* @param QTcpServer()
*/
class client;
class server : public QTcpServer
{
    Q_OBJECT
public:
    void change_cmd(QString a);
    server(QObject *parent = nullptr);
    bool startServer(quint16 port); //Metodo para iniciar el servidor
    QString CMD; //String de los mensajes que se mostraran en consola.
    int porcent; //Porcentage que se mostrara en la aplicacion TECFS
    QString Received_Message; //String Asignado al mensaje recivido
protected:
    void incomingConnection(qintptr handle); //Metodo protegido del QServer
signals:
    void cmd_change();
private:
    void Send_Message(QString message); //Metodo para enviar un mensaje
    void Do_Action(); //Metodo que realiza la interpretacion de los mensajes
    QList<client *> mSockets; //Lista de los clientes conectados
};
#endif // SERVER_H
