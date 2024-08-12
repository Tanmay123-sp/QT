#include "stack.h"
#include "ui_stack.h"

stack::stack(map<QString,bool>&categoryMap,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stack),
    newcategoryMap(categoryMap)
{
    ui->setupUi(this);
}

stack::~stack()
{
    delete ui;
}

void stack::on_radioButtonTech_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    for(auto &it : newcategoryMap){
        if(it.second == true){
            ui->comboBox->addItem(it.first);
        }
    }

}


void stack::on_radioButtonNonTech_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    for(auto &it : newcategoryMap){
        if(it.second == false){
            ui->comboBox_2->addItem(it.first);
        }
    }
}

