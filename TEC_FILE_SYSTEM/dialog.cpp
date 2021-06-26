#include "dialog.h"
#include "ui_dialog.h"
/**
* \brief Ventana que se encarga de optener el puerto al que se
* conectara la apliacion.
*/
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
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
/**
* \brief Accion que ejecuta la ventana
* al presionar el boton de cancelar.
*/
void Dialog::on_Cancel_clicked()
{
    reject(); //emite el comando rechazar de la aplicacion
}
