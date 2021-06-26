#include "tecfs.h"
#include <QApplication>
/**
* \brief Ejecucion inicial de la aplicacion.
* @param QApplication
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //Define la aplicacion
    TECFS w; // Define la ventana principal
    w.show(); // Muestra la ventana principal
    return a.exec();
}
