#include "mainwindow.h"

#include <QApplication>
/**
* \brief Main de la aplicacion, centro de ejecucion.
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; //Inicializacion de la ventana
    w.show(); //Ejecucion de la mismas
    return a.exec();
}
