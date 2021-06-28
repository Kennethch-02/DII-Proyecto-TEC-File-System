#include "archive.h"
#include "ui_archive.h"

Archive::Archive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Archive)
{
    ui->setupUi(this);
}
void Archive::set_text()
{
    ui->TEXT->setText(text);
}
