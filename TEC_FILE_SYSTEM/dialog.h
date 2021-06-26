#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
/**
* \brief Ventana que se encarga de optener el puerto al que se
* conectara la apliacion.
*/
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    int port; //Numero del puerto a conectarse
    explicit Dialog(QWidget *parent = nullptr);

private slots:
    void on_Connect_clicked(); //Cuando se presiona el boton Connect
    void on_Cancel_clicked(); //Cuando se presiona el boton Cancel

private:
    Ui::Dialog *ui; //Puntero a la aplicacion
};

#endif // DIALOG_H
