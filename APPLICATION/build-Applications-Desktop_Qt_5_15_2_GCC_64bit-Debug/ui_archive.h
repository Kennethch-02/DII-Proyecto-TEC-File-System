/********************************************************************************
** Form generated from reading UI file 'archive.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCHIVE_H
#define UI_ARCHIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Archive
{
public:
    QGridLayout *gridLayout;
    QTextEdit *TEXT;

    void setupUi(QDialog *Archive)
    {
        if (Archive->objectName().isEmpty())
            Archive->setObjectName(QString::fromUtf8("Archive"));
        Archive->resize(682, 564);
        gridLayout = new QGridLayout(Archive);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TEXT = new QTextEdit(Archive);
        TEXT->setObjectName(QString::fromUtf8("TEXT"));
        TEXT->setReadOnly(true);

        gridLayout->addWidget(TEXT, 0, 0, 1, 1);


        retranslateUi(Archive);

        QMetaObject::connectSlotsByName(Archive);
    } // setupUi

    void retranslateUi(QDialog *Archive)
    {
        Archive->setWindowTitle(QCoreApplication::translate("Archive", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Archive: public Ui_Archive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVE_H
