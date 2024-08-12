/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *newBook;
    QLabel *newBook_count;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButtonTech;
    QRadioButton *radioButtonNonTech;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(557, 300);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(126, 70, 240, 60));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        newBook = new QLabel(layoutWidget);
        newBook->setObjectName("newBook");

        verticalLayout->addWidget(newBook);

        newBook_count = new QLabel(layoutWidget);
        newBook_count->setObjectName("newBook_count");

        verticalLayout->addWidget(newBook_count);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEdit1 = new QLineEdit(layoutWidget);
        lineEdit1->setObjectName("lineEdit1");

        verticalLayout_2->addWidget(lineEdit1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_2->addWidget(lineEdit_2);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget_2 = new QWidget(Dialog);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(130, 220, 231, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        insertButton = new QPushButton(layoutWidget_2);
        insertButton->setObjectName("insertButton");

        horizontalLayout_2->addWidget(insertButton);

        deleteButton = new QPushButton(layoutWidget_2);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_2->addWidget(deleteButton);

        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(130, 160, 214, 25));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButtonTech = new QRadioButton(widget);
        radioButtonTech->setObjectName("radioButtonTech");

        horizontalLayout_3->addWidget(radioButtonTech);

        radioButtonNonTech = new QRadioButton(widget);
        radioButtonNonTech->setObjectName("radioButtonNonTech");

        horizontalLayout_3->addWidget(radioButtonNonTech);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        newBook->setText(QCoreApplication::translate("Dialog", "Book Name :", nullptr));
        newBook_count->setText(QCoreApplication::translate("Dialog", "Quantity :", nullptr));
        insertButton->setText(QCoreApplication::translate("Dialog", "insert", nullptr));
        deleteButton->setText(QCoreApplication::translate("Dialog", "delete", nullptr));
        radioButtonTech->setText(QCoreApplication::translate("Dialog", "Technical", nullptr));
        radioButtonNonTech->setText(QCoreApplication::translate("Dialog", "non-Technical", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
