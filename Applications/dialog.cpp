#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
/**
* \brief Accion que ejecuta la ventana
* al presionar el boton de cancelar.
*/
void Dialog::on_Back_clicked()
{
    reject();
}
/**
* \brief Accion que ejecuta la ventana
* al presionar el boton de conectar.
*/
void Dialog::on_Connect_clicked()
{
    port = ui->port->value();
    accept(); //emite el comando aceptar de la aplicacion
}
