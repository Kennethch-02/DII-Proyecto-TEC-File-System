#include "test_application.h"
#include "ui_test_application.h"

Test_Application::Test_Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test_Application)
{
    ui->setupUi(this);
}

Test_Application::~Test_Application()
{
    delete ui;
}
