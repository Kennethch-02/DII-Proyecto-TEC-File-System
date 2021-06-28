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
    thread = new Thread(this);
    connect(thread, &Thread::already, [&](){ //Crea la conneccion con la señal del Thread
            emit update(); //emite la señal asignada
        });
    connect(&Server, &server::cmd_change, [&](){
            emit change();
        });
    connect(this, &TECFS::update, //Conecta la señal asignada con el metodo Update()
                &TECFS::Update);

    connect(this, &TECFS::change,
                &TECFS::Append_CMD);

    thread->start(10,QThread::HighPriority); //Inicia el Thread ejecutandose cada 10ms
    controller_node.write_book("/home/kenneth/Proyecto-TEC-File-System/TEC_FILE_SYSTEM/books");

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
/**
* \brief Metodo update de la aplicacion, que se ejecuta segùn la señal del Thread
*/
void TECFS::Update()
{
}
