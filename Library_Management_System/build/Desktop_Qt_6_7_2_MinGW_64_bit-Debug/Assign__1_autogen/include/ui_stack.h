/********************************************************************************
** Form generated from reading UI file 'stack.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACK_H
#define UI_STACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stack
{
public:
    QLabel *label_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButtonTech;
    QRadioButton *radioButtonNonTech;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *page_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;

    void setupUi(QDialog *stack)
    {
        if (stack->objectName().isEmpty())
            stack->setObjectName("stack");
        stack->resize(677, 347);
        label_3 = new QLabel(stack);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 10, 211, 21));
        layoutWidget_2 = new QWidget(stack);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(110, 70, 214, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButtonTech = new QRadioButton(layoutWidget_2);
        radioButtonTech->setObjectName("radioButtonTech");

        horizontalLayout_3->addWidget(radioButtonTech);

        radioButtonNonTech = new QRadioButton(layoutWidget_2);
        radioButtonNonTech->setObjectName("radioButtonNonTech");

        horizontalLayout_3->addWidget(radioButtonNonTech);

        stackedWidget = new QStackedWidget(stack);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(50, 120, 601, 271));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));
        page = new QWidget();
        page->setObjectName("page");
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 40, 211, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        layoutWidget_3 = new QWidget(page_2);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(70, 40, 211, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_3);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(layoutWidget_3);
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout_2->addWidget(comboBox_2);

        stackedWidget->addWidget(page_2);

        retranslateUi(stack);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(stack);
    } // setupUi

    void retranslateUi(QDialog *stack)
    {
        stack->setWindowTitle(QCoreApplication::translate("stack", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("stack", "Library Managemanet System", nullptr));
        radioButtonTech->setText(QCoreApplication::translate("stack", "Technical", nullptr));
        radioButtonNonTech->setText(QCoreApplication::translate("stack", "non-Technical", nullptr));
        label->setText(QCoreApplication::translate("stack", "Book List:", nullptr));
        label_2->setText(QCoreApplication::translate("stack", "Book List:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stack: public Ui_stack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACK_H
