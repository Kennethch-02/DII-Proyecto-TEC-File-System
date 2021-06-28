#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QDialog>
/**
* \brief Ventana encargada de mostrar el texto de los archivos txt cargados.
*/
namespace Ui {
class Archive;
}

class Archive : public QDialog
{
    Q_OBJECT

public:
    explicit Archive(QWidget *parent = nullptr);
    QString text; //Texto que se mostrara
    void set_text(); //Metodo para mostar el texto

private:
    Ui::Archive *ui;
};

#endif // ARCHIVE_H
