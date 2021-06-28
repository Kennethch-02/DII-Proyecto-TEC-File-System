#ifndef TECFS_H
#define TECFS_H

#include <QMainWindow>
#include <server.h>
#include <thread.h>
#include <controller_node.h>

/**
* \brief Aplicacion grafica para TEC FIle System, muestra el estado del
* servidor y de la aplicacion Controller Node, especificamente el estado de su funcionamiento.
* @param QMainWindow
*/
QT_BEGIN_NAMESPACE
namespace Ui {class TECFS;}
QT_END_NAMESPACE

class Thread;
class TECFS : public QMainWindow
{
    Q_OBJECT
public:
    explicit TECFS(QWidget *parent = nullptr); //inicializacion de la aplicacion
private slots:
    void Update(); //Slot asignado para hacer el Update conectado al Thread
    void on_connect_clicked(); //Cuando se presiona el boton Conectar
    void Append_CMD();
signals:
    void update(); //Señal para realizar el update
    void change();
private:
    Controller_Node controller_node;
    server Server; //Clase servidor
    Thread *thread; //Clase Thread
    Ui::TECFS *ui; //Puntero a la interfaz grafica
};
#endif // TECFS_H
