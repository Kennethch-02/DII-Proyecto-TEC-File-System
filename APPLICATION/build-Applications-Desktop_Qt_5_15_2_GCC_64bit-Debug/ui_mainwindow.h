/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *Path;
    QPushButton *bth_path;
    QPushButton *Connect;
    QPushButton *btn_search;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *Search;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Path = new QLineEdit(centralwidget);
        Path->setObjectName(QString::fromUtf8("Path"));

        gridLayout->addWidget(Path, 1, 1, 1, 1);

        bth_path = new QPushButton(centralwidget);
        bth_path->setObjectName(QString::fromUtf8("bth_path"));
        bth_path->setEnabled(false);

        gridLayout->addWidget(bth_path, 1, 2, 1, 2);

        Connect = new QPushButton(centralwidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));

        gridLayout->addWidget(Connect, 0, 3, 1, 1);

        btn_search = new QPushButton(centralwidget);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setEnabled(false);

        gridLayout->addWidget(btn_search, 3, 2, 1, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font.setPointSize(21);
        font.setItalic(true);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 3);

        Search = new QLineEdit(centralwidget);
        Search->setObjectName(QString::fromUtf8("Search"));

        gridLayout->addWidget(Search, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout_2->addWidget(listWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Path->setText(QCoreApplication::translate("MainWindow", "/home/kenneth/Proyecto-TEC-File-System/TEC_FILE_SYSTEM/books", nullptr));
        bth_path->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        Connect->setText(QCoreApplication::translate("MainWindow", "Connect to Server", nullptr));
        btn_search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">CeRobot</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">CeSearch</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Test Application", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
