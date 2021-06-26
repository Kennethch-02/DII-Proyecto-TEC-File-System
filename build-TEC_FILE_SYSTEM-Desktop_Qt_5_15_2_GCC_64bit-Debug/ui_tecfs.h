/********************************************************************************
** Form generated from reading UI file 'tecfs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TECFS_H
#define UI_TECFS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TECFS
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *s_controller;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QProgressBar *progressBar;
    QTextEdit *CMD_;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *connect;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QLabel *s_server;
    QLabel *label_2;

    void setupUi(QMainWindow *TECFS)
    {
        if (TECFS->objectName().isEmpty())
            TECFS->setObjectName(QString::fromUtf8("TECFS"));
        TECFS->resize(633, 513);
        TECFS->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);\n"
"color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(TECFS);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 130, 270, 50));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        s_controller = new QLabel(layoutWidget);
        s_controller->setObjectName(QString::fromUtf8("s_controller"));

        gridLayout_2->addWidget(s_controller, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 210, 631, 301));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(layoutWidget1);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, progressBar);

        CMD_ = new QTextEdit(layoutWidget1);
        CMD_->setObjectName(QString::fromUtf8("CMD_"));
        CMD_->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, CMD_);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 10, 611, 39));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("AnjaliOldLipi"));
        font.setPointSize(20);
        font.setItalic(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        connect = new QPushButton(layoutWidget2);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(connect);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 70, 184, 50));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        s_server = new QLabel(layoutWidget3);
        s_server->setObjectName(QString::fromUtf8("s_server"));

        gridLayout->addWidget(s_server, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        TECFS->setCentralWidget(centralwidget);

        retranslateUi(TECFS);

        QMetaObject::connectSlotsByName(TECFS);
    } // setupUi

    void retranslateUi(QMainWindow *TECFS)
    {
        TECFS->setWindowTitle(QCoreApplication::translate("TECFS", "MainWindow", nullptr));
        s_controller->setText(QCoreApplication::translate("TECFS", "<html><head/><body><p align=\"center\"><span style=\" color:#ef2929;\">DISCONNECTED</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("TECFS", "<html><head/><body><p align=\"center\">CONTROLLER NODE...</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("TECFS", "TEC FILE SYSTEM", nullptr));
        connect->setText(QCoreApplication::translate("TECFS", "START", nullptr));
        s_server->setText(QCoreApplication::translate("TECFS", "<html><head/><body><p align=\"center\"><span style=\" color:#ef2929;\">DISCONNECTED</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("TECFS", "<html><head/><body><p align=\"center\">SERVER...</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TECFS: public Ui_TECFS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TECFS_H
