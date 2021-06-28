#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QDir>
#include <archive.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
        auto text = T.readAll();
        Interpreter_Message(text);
    });
}

void MainWindow::Connect(int port)
{
    mSocket->connectToHost("localhost", port);
}
void MainWindow::Interpreter_Message(QString message)
{
    QStringList lines = message.split("\n");
    for (QString& word:lines) {
        if(word!=""){
            ui->listWidget->addItem(word);
        }
    }
}
void MainWindow::Send_Message(QString message)
{
    QTextStream A(mSocket);
    A<<message;
    A.flush();
}
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

void MainWindow::on_bth_path_clicked()
{
    ui->btn_search->setDisabled(false);
    Path = ui->Path->text();
    QString m = "Path&"+ui->Path->text();
    Send_Message(m);
}

void MainWindow::on_btn_search_clicked()
{
    QString m = "Search&"+ui->Search->text();
    Send_Message(m);
    ui->listWidget->clear();
}

void MainWindow::on_listWidget_itemPressed(QListWidgetItem *item)
{
    Archive a(this);
    QString b = item->text();
    QString rute = Path+"/"+b.split(" ")[1];
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
    a.exec();

}
