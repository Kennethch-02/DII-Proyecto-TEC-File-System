#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QDir>
#include <archive.h>
/**
* \brief Window Princial de ejecucion, realiza las instruciones necesarias para
* las apliaciones de prueba.
* \param MainWindow
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){ //Coneccion del Socket para recibir mensajes
        QTextStream T(mSocket);
        auto text = T.readAll();
        Interpreter_Message(text); //Decodificacion Huffman
    });
}
/**
* \brief Metodo encargado de conectar el cliente a el servidor
*/
void MainWindow::Connect(int port)
{
    mSocket->connectToHost("localhost", port);
}
/**
* \brief Metodo encargado de interpretar los mensajes recibidos por el servidor, realiza las
* instruciones necesarias del mismo.
*/
void MainWindow::Interpreter_Message(QString message)
{
    QStringList lines = message.split("\n");
    for (QString& word:lines) {
        if(word!=""){
            ui->listWidget->addItem(word); //Agrega las palabras encontradas por el metodo search a la interfaz grafica
        }
    }
}
/**
* \brief Metodo encargado de enviar mensajes desde el cliente
*/
void MainWindow::Send_Message(QString message)
{
    QTextStream A(mSocket);
    A<<message; //Envio de mensajes codificados
    A.flush();
}
/**
* \brief Cuadro de dialogo mostrado cuando se hace click en el boton de Connect,
* para realiar la coneccion con el servidor
*/
void MainWindow::on_Connect_clicked()
{
    Dialog m(this); //inicial el cuadro de dialogo
    if(m.exec() == QDialog::Rejected){ //Comprueba que el dialogo no sea cerrado
        return;
    }else{
        Connect(m.port);
        ui->bth_path->setDisabled(false);
    }
}
/**
* \brief Ejecuta las instrucciones al presionar le boton Path
*/
void MainWindow::on_bth_path_clicked()
{
    ui->btn_search->setDisabled(false);
    Path = ui->Path->text();
    QString m = "Path&"+ui->Path->text();
    Send_Message(m);
}
/**
* \brief Ejecuta las instrucciones al presionar el boton Search.
*/
void MainWindow::on_btn_search_clicked()
{
    QString m = "Search&"+ui->Search->text();
    Send_Message(m);
    ui->listWidget->clear();
}
/**
* \brief Metodo encargado de mostrar el archivo txt seleccionado en pantalla
* para efectos de comprobar la existencia del mismo.
*/
void MainWindow::on_listWidget_itemPressed(QListWidgetItem *item)
{
    Archive a(this); //Inicializa la ventana
    QString b = item->text();
    QString rute = Path+"/"+b.split(" ")[1]; //Abre el archivo a partir del Path y el item
    QFile inputFile(rute);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            a.text.append(in.readLine());
        }inputFile.close();
    }
    a.set_text();
    a.exec(); // Ejecuta la ventana con el texto ya cargado.

}
