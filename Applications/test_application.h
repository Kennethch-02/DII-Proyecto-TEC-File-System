#ifndef TEST_APPLICATION_H
#define TEST_APPLICATION_H

#include <QMainWindow>

namespace Ui {
class Test_Application;
}

class Test_Application : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test_Application(QWidget *parent = nullptr);
    ~Test_Application();

private:
    Ui::Test_Application *ui;
};

#endif // TEST_APPLICATION_H
