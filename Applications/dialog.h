#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    int port;

private slots:
    void on_Back_clicked();

    void on_Connect_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
