#ifndef TECFS_H
#define TECFS_H

#include <QMainWindow>
#include <server.h>
#include <controller_node.h>

/**
* \brief Aplicacion grafica para TEC FIle System, muestra el estado del
* servidor y de la aplicacion Controller Node, especificamente el estado de su funcionamiento.
* @param QMainWindow
*/
QT_BEGIN_NAMESPACE
namespace Ui {class TECFS;}
QT_END_NAMESPACE

class TECFS : public QMainWindow
{
    Q_OBJECT
public:
    explicit TECFS(QWidget *parent = nullptr); //inicializacion de la aplicacion
private slots:
    void on_connect_clicked(); //Cuando se presiona el boton Conectar
    void Append_CMD();
    void Interpreter_Message();
signals:
    void update(); //Señal para realizar el update
    void change();
    void r_message();
private:
    Controller_Node controller_node;
    server Server; //Clase servidor
    Ui::TECFS *ui; //Puntero a la interfaz grafica
};
#endif // TECFS_H
