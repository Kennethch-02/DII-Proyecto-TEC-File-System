#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QDialog>

namespace Ui {
class Archive;
}

class Archive : public QDialog
{
    Q_OBJECT

public:
    explicit Archive(QWidget *parent = nullptr);
    QString text;
    void set_text();

private:
    Ui::Archive *ui;
};

#endif // ARCHIVE_H
