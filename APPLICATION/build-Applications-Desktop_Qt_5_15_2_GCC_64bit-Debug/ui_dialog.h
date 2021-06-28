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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *Connect;
    QPushButton *Back;
    QSpinBox *port;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(383, 171);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Connect = new QPushButton(Dialog);
        Connect->setObjectName(QString::fromUtf8("Connect"));

        gridLayout->addWidget(Connect, 2, 2, 1, 1);

        Back = new QPushButton(Dialog);
        Back->setObjectName(QString::fromUtf8("Back"));

        gridLayout->addWidget(Back, 2, 1, 1, 1);

        port = new QSpinBox(Dialog);
        port->setObjectName(QString::fromUtf8("port"));
        port->setMinimum(1200);
        port->setMaximum(1233221);
        port->setSingleStep(10);

        gridLayout->addWidget(port, 0, 1, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:16pt;\">Port</span></p></body></html>", nullptr));
        Connect->setText(QCoreApplication::translate("Dialog", "Connect", nullptr));
        Back->setText(QCoreApplication::translate("Dialog", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
