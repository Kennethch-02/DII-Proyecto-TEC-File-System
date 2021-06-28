#include "tecfs.h"
#include "ui_tecfs.h"
#include "dialog.h"
#include "controller_node.h"
/**
* \brief Aplicacion grafica para TEC FIle System, muestra el estado del
* servidor y de la aplicacion Controller Node, especificamente el estado de su funcionamiento.
* @param QMainWindow
*/
TECFS::TECFS(QWidget *parent) :

    QMainWindow(parent), //Criterios iniciales para laventana
    ui(new Ui::TECFS)
{
    ui->setupUi(this);
    connect(&Server, &server::cmd_change, [&](){
            emit change();
        });
    connect(&Server, &server::R_Message, [&](){
            emit r_message();
        });
    connect(this, &TECFS::change,
                &TECFS::Append_CMD);
    connect(this, &TECFS::r_message,
                &TECFS::Interpreter_Message);
    //controller_node.write_book("/home/kenneth/Proyecto-TEC-File-System/TEC_FILE_SYSTEM/books");
    //qDebug()<<controller_node.read_book("los").split("/");
}
/**
* \brief Metodo que se encarga de ejecutar la accion que realiza el servidor
* al precional el boton de START de la interfaz
*/
void TECFS::on_connect_clicked()
{

    Dialog m(this); //inicial el cuadro de dialogo
    if(m.exec() == QDialog::Rejected){ //Comprueba que el dialogo no sea cerrado
        return;
    }else{
        if(Server.startServer(m.port)){
            Server.change_cmd("Servidor Iniciado en el puerto: " + QString::number(m.port));//Comprueba que exista forma de conectarse a este puerto
            ui->s_server->setText("CONNECTED"); //Cambia el estado del servidor en pantalla
            ui->connect->setDisabled(true); //Desabilita el uso del boton START
        }
    }
}

void TECFS::Append_CMD()
{
    ui->CMD_->setText(Server.CMD);
}

void TECFS::Interpreter_Message()
{
    QString message = Server.Received_Message;
    QStringList m_split = message.split("&");
    if(m_split[0]=="Path"){
        QString str1 = m_split[1];
        QByteArray ba = str1.toLocal8Bit();
        char *c_str2 = ba.data();
        controller_node.write_book(c_str2);
    }
    if(m_split[0]=="Search"){
        Server.Send_Message(controller_node.read_book(m_split[1]));
    }
}

