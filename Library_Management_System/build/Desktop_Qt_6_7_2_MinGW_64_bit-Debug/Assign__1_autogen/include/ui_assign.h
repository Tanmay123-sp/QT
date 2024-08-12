/********************************************************************************
** Form generated from reading UI file 'assign.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGN_H
#define UI_ASSIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assign
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QComboBox *comboBox_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Tech;
    QRadioButton *radioButton_NonTech;
    QRadioButton *radioButtonAll;

    void setupUi(QDialog *Assign)
    {
        if (Assign->objectName().isEmpty())
            Assign->setObjectName("Assign");
        Assign->resize(649, 337);
        label = new QLabel(Assign);
        label->setObjectName("label");
        label->setGeometry(QRect(106, 120, 61, 20));
        label_2 = new QLabel(Assign);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 180, 67, 17));
        label_3 = new QLabel(Assign);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 240, 67, 17));
        comboBox_3 = new QComboBox(Assign);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(210, 170, 86, 25));
        comboBox_2 = new QComboBox(Assign);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(210, 120, 86, 25));
        textEdit = new QTextEdit(Assign);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(210, 239, 104, 21));
        pushButton = new QPushButton(Assign);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 290, 89, 25));
        label_4 = new QLabel(Assign);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(86, 70, 111, 20));
        widget = new QWidget(Assign);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(210, 70, 350, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_Tech = new QRadioButton(widget);
        radioButton_Tech->setObjectName("radioButton_Tech");

        horizontalLayout->addWidget(radioButton_Tech);

        radioButton_NonTech = new QRadioButton(widget);
        radioButton_NonTech->setObjectName("radioButton_NonTech");

        horizontalLayout->addWidget(radioButton_NonTech);

        radioButtonAll = new QRadioButton(widget);
        radioButtonAll->setObjectName("radioButtonAll");

        horizontalLayout->addWidget(radioButtonAll);


        retranslateUi(Assign);

        QMetaObject::connectSlotsByName(Assign);
    } // setupUi

    void retranslateUi(QDialog *Assign)
    {
        Assign->setWindowTitle(QCoreApplication::translate("Assign", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Assign", "Book", nullptr));
        label_2->setText(QCoreApplication::translate("Assign", "User ", nullptr));
        label_3->setText(QCoreApplication::translate("Assign", "Quantity", nullptr));
        pushButton->setText(QCoreApplication::translate("Assign", "Assign ", nullptr));
        label_4->setText(QCoreApplication::translate("Assign", " Book Category", nullptr));
        radioButton_Tech->setText(QCoreApplication::translate("Assign", "Tech", nullptr));
        radioButton_NonTech->setText(QCoreApplication::translate("Assign", "Non-Tech", nullptr));
        radioButtonAll->setText(QCoreApplication::translate("Assign", "All Books", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assign: public Ui_Assign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGN_H
