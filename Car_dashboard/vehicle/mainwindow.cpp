#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dt1 = new dataProvider1();
    qDebug()<< "hi";
    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::dashWin);
    connect(ui->userButton,&QPushButton::clicked,this,&MainWindow::userWin);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dt1;
}

userModel MainWindow::getLastUserfromDP()
{
    return dt1->getLastUserInfofromDB();
}

// void MainWindow::setBg(QString user, QString color, QString mode)
// {
//     dd1->setBgfromMain(user, color, mode);
// }

// QVector<QString> MainWindow::getUserInfofromDP()
// {
//     dt1->getUserfromDataInfo();
// }


// void MainWindow::resetFun()
// {
//     dt1->speed=0;
//     qDebug()<<dt1->speed;
// }

void MainWindow::dashWin()
{
    qDebug() <<dt1->getLastUserInfofromDB().getuserName();
    qDebug() <<" main"<<dt1->getVehicleDatafromDB()[0].getTotslKm();
    dd1 = new dashboard1(dt1->getLastUserInfofromDB(),dt1->getVehicleDatafromDB(),this);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&MainWindow::timer2_fun);
    connect(timer1,&QTimer::timeout,this,&MainWindow::timer1_fun);
    connect(dd1,&dashboard1::exportEngKm,this,&MainWindow::getEngKmfromDash);

    timer1->start(3000);
    timer2->start(200);
}

void MainWindow::userWin()
{
    uObj1 = new user(dt1->getUserfromDataInfo(),dt1->getLastUserInfofromDB(), this);

    connect(uObj1,&user::exportName1,this,&MainWindow::getUser1);
    uObj1->show();
    connect(uObj1,&user::exportBg,this,&MainWindow::setBgfromUser);
    // uObj1->updateCombo();
}

void MainWindow::timer1_fun()
{
    dd1->show();
    timer1->stop();
}

void MainWindow::timer2_fun()
{
    ui->startButton->setStyleSheet(
        "border-radius: 45px;" /* Half of the desired button size */
        "background-color: green;" /* red color */
        "color: black;" /* Text color */
        "padding: 15px");
}

void MainWindow::on_resetButton_clicked()
{
    // dt1->resetFun();
    connect(this,&MainWindow::resetFun,dd1,&dashboard1::resetValues);
    emit resetFun(0,0);
    dt1->getEngineHrsfromMain(0,0);
}

void MainWindow::getUser1(QString name)
{
    dt1->setUserName(name);
}

void MainWindow::getEngKmfromDash(int engineHrs,int totalKm)
{
    int engine=engineHrs;
    int Km=totalKm;
    qDebug()<<engine<<" value from dash to main"<<totalKm;
    dt1->getEngineHrsfromMain(engine,Km);
}

void MainWindow::setBgfromUser(QString uName, QString color, QString mode)
{
    dd1->setBgfromMain(uName, color, mode);
    dt1->setCurrentUser(uName, color, mode);
}

