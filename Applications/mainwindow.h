#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
* \brief Window Princial de ejecucion, realiza las instruciones necesarias para
* las apliaciones de prueba.
* \param MainWindow
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    QTcpSocket *mSocket;
    void Connect(int port);
    QString Path;
private slots:
    void on_Connect_clicked();
    void on_bth_path_clicked();
    void on_btn_search_clicked();
    void on_listWidget_itemPressed(QListWidgetItem *item);

private:
    void Interpreter_Message(QString message);
    void Send_Message(QString message);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
