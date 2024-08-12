#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QString>
#include<QComboBox>
#include<QWidget>
#include "dialog.h"
#include<QComboBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bookMap = {
        {"C++", {2, {{"Sagar", 1}}}},
        {"Java", {3, {{"Nilesh", 2}}}},
        {"Python", {2, {{"Hari", 1}}}},
        {"Linux", {4, {{"Mahesh", 1}}}},
        {"Novel", {4, {{"Manish", 1}}}}
    };
    //connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(EachBookQty()));
    categoryMap={
        {"C++",1},
        {"Java",1},
        {"Python",1},
        {"Linux",1},
        {"Novel",0}
    };
    add_Books();
    count_Books();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: add_Books(){
     ui->comboBox->clear();
    for(  auto  &it:bookMap){

       ui->comboBox->addItem(it.first + "  - " + QString::number(it.second.first));
        // ui->comboBox->addItem(it.first);
      }
}

void MainWindow::on_pushButton_clicked()
{    di = new Dialog(bookMap,categoryMap);
    connect(di , &Dialog::booksUpdated , this , &MainWindow::update_1);
    connect(di , &Dialog::booksUpdated_1 ,this , &MainWindow::update_2);
    di->show();
}

void MainWindow::update_1(QString name,int count,bool selectCat){
    // bookMap[name].first += count;
    add_Books();
    MainWindow:: count_Books();
}

void MainWindow::update_2(QString name,int count){
    // bookMap[name].first += count;
    add_Books();
    MainWindow:: count_Books();
}

void MainWindow :: count_Books(){
    int total_books =0;
    for(auto &count : bookMap){
        total_books += count.second.first;
    }
    ui->lineEdit->setText(QString :: number(total_books));
}

void MainWindow::on_assign_button_clicked()
{
    ass = new Assign(bookMap,categoryMap);
    ass->show();

}

void MainWindow::on_detailsButton_clicked()
{
    dt = new details(bookMap,categoryMap);
    dt->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    st=new stack(categoryMap);
    st->show();

}

