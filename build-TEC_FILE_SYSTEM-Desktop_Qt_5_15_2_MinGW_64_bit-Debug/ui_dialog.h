/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Connect;
    QPushButton *Cancel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *port;
    QSpinBox *memory;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(316, 112);
        horizontalLayoutWidget = new QWidget(Dialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 70, 201, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Connect = new QPushButton(horizontalLayoutWidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));

        horizontalLayout->addWidget(Connect);

        Cancel = new QPushButton(horizontalLayoutWidget);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        horizontalLayout->addWidget(Cancel);

        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 311, 61));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        port = new QSpinBox(widget);
        port->setObjectName(QString::fromUtf8("port"));
        port->setMinimum(1200);
        port->setMaximum(120000);

        gridLayout->addWidget(port, 1, 2, 1, 1);

        memory = new QSpinBox(widget);
        memory->setObjectName(QString::fromUtf8("memory"));
        memory->setMinimumSize(QSize(200, 0));
        memory->setMinimum(2048);
        memory->setMaximum(20000);

        gridLayout->addWidget(memory, 0, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Connect->setText(QCoreApplication::translate("Dialog", "Connnect", nullptr));
        Cancel->setText(QCoreApplication::translate("Dialog", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Port", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Memory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
