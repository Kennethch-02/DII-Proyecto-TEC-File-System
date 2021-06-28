#include "archive.h"
#include "ui_archive.h"
/**
* \brief Ventana encargada de mostrar el texto de los archivos txt cargados.
*/
Archive::Archive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Archive)
{
    ui->setupUi(this);
}
/**
* \brief Coloca el texto en el elemento grafico TEXT
*/
void Archive::set_text()
{
    ui->TEXT->setText(text);
}
