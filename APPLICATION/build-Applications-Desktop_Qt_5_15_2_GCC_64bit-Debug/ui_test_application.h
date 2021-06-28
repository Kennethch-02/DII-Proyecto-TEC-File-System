/********************************************************************************
** Form generated from reading UI file 'test_application.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_APPLICATION_H
#define UI_TEST_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test_Application
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Test_Application)
    {
        if (Test_Application->objectName().isEmpty())
            Test_Application->setObjectName(QString::fromUtf8("Test_Application"));
        Test_Application->resize(640, 480);
        menubar = new QMenuBar(Test_Application);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Test_Application->setMenuBar(menubar);
        centralwidget = new QWidget(Test_Application);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Test_Application->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Test_Application);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Test_Application->setStatusBar(statusbar);

        retranslateUi(Test_Application);

        QMetaObject::connectSlotsByName(Test_Application);
    } // setupUi

    void retranslateUi(QMainWindow *Test_Application)
    {
        Test_Application->setWindowTitle(QCoreApplication::translate("Test_Application", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test_Application: public Ui_Test_Application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_APPLICATION_H
