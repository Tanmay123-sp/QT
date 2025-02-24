#include "assign.h"
#include "ui_assign.h"
#include<map>
#include<QDebug>
#include <QMessageBox>

using namespace std;
Assign::Assign(map<QString,pair<int,map<QString,int>>>&bookMap,map<QString,bool>&categoryMap,QWidget *parent)
    : QDialog(parent),
    newbookMap(bookMap),
    newCategoryMap(categoryMap)

    , ui(new Ui::Assign)
{
    ui->setupUi(this);
    ui->radioButtonAll->setChecked(true);


    add_Books();
    add_user();
}

Assign::~Assign()
{
    delete ui;
}


void Assign :: add_Books(){
    ui->comboBox_2->clear();
    for(  auto  &it:newbookMap){

        ui->comboBox_2->addItem(it.first);
    }
}

void Assign::add_user(){
    ui->comboBox_3->clear();
    for(auto &it:newbookMap){
        for(auto &it2 : it.second.second)
        {
            ui->comboBox_3->addItem(it2.first);
        }
    }
}

void Assign::on_pushButton_clicked()
{
    QString S_name = ui->comboBox_2->currentText();
    QString u_name = ui->comboBox_3->currentText();
    int Qty = ui->textEdit->toPlainText().toInt();

    // auto it= newbookMap[S_name];
    int totalQuantity = newbookMap[S_name].first;
    qDebug() << "numbwers RWJENBD "<<S_name<<totalQuantity<<Qty;

    if(newbookMap.find(S_name) != newbookMap.end())
    {
        if(totalQuantity >= Qty){
            qDebug() << "ygtgbvnhnbjgvgjncgn"<<totalQuantity;

            newbookMap[S_name].second[u_name]+=Qty;
            qDebug()<<newbookMap[S_name].second[u_name];
        }else{
            QMessageBox::warning(nullptr, "Error","Error");

        }
    }
}

void Assign::on_radioButton_Tech_clicked()
{
    ui->comboBox_2->clear();
    for(auto it : newCategoryMap)
    {
        if(it.second == true)
        {
            ui->comboBox_2->addItem(it.first);
        }
    }
}


void Assign::on_radioButtonAll_clicked()
{
    add_Books();
}


void Assign::on_radioButton_NonTech_clicked()
{
    ui->comboBox_2->clear();
    for(auto it : newCategoryMap)
    {
        if(it.second == false)
        {
            ui->comboBox_2->addItem(it.first);
        }
    }
}
