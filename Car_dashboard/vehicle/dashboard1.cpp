#include "dashboard1.h"
#include "ui_dashboard1.h"

dashboard1::dashboard1(userModel LastUserObj,QVector<vehicleModel>getInfo,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dashboard1),
    obj(LastUserObj),
    vehicleInfo(getInfo)
{
    ui->setupUi(this);
    totalEngineHrs = vehicleInfo[0].getEngineHrs();
    speed = 0;
    // totalKm=0;
    if(obj.getMode()=="Eco"){
        rpm1= 3000;

    }
    else{
        rpm1 = 6000;
    }

    totalKm = vehicleInfo[0].getTotslKm();
    LastUserBG();
    connect(batteryTimer, &QTimer::timeout,this,&dashboard1::BatteryLevel);
    batteryTimer->start(20000);
    // ui->totalKmLCD->display(vehicleInfo[0].getTotslKm());
    qDebug()<<"km"<<vehicleInfo[0].getTotslKm();
    connect(engineTimer,&QTimer::timeout,this,&dashboard1::EngineHrs);
    engineTimer->start(5000);

    connect(speedTimer,&QTimer::timeout,this,&dashboard1::SpeedLevel);
    speedTimer->start(3000);

    // connect(ui->dial, &QDial::valueChanged, this, &dashboard1::updateSpeedometer);
    connect(kmTimer, &QTimer::timeout, this,&dashboard1::totalKmFun );
    kmTimer->start(3000);
    ui->leftLabel->setVisible(false);
    ui->rightLabel->setVisible(false);

}

dashboard1::~dashboard1()
{
    kmTimer->stop();
    delete ui;
    delete kmTimer;
    // emit exportTotalKm(totalKm);
}

void dashboard1::LastUserBG()
{
    QString styleSheet = QString("background-color: %1;");
    qDebug()<<styleSheet;

    if(obj.getColor()=="black"){
        qDebug()<<obj.getColor();
        QString c1=obj.getColor();
        styleSheet = QString(styleSheet).arg(obj.getColor());
            qDebug()<<"gyhgjhgjgjhjhj"<<styleSheet;
            this->setStyleSheet(styleSheet);
            // this->setStyleSheet("background-color:'black';");
    }
    else if(obj.getColor()=="blue"){
        styleSheet = QString(styleSheet).arg(obj.getColor());
            qDebug()<<"gyhgjhgjgjhjhj"<<styleSheet;
        this->setStyleSheet(styleSheet);
    }
    else if(obj.getColor()=="grey"){
        styleSheet = QString(styleSheet).arg(obj.getColor());
        qDebug()<<"gyhgjhgjgjhjhj"<<styleSheet;
        this->setStyleSheet(styleSheet);
    }
}

//
int dashboard1::getBattery()
{
    return battery;
}

void dashboard1::setBgfromMain(QString user, QString color, QString mode)
{
    user =user;
    color = color;
    mode = mode;
    qDebug()<<user<<"ggg"<<color<<mode;
    QString styleSheet = QString("background-color: %1;").arg(color);
    qDebug()<<styleSheet;
    this->setStyleSheet(styleSheet);
}
//qDebug()<<user<<"ggg"<<color<<mode;

// int dashboard1::getEngineHrs()
// {
//     return totalEngineHrs;
// }


int dashboard1::calculateRPM(int speed)
{
    qDebug()<<"calculate"<<speed;
     return speed * 10;

}

void dashboard1::closeEvent(QCloseEvent *event)
{
    emit exportEngKm(totalEngineHrs,totalKm);
    QWidget:: closeEvent(event);
}

// void dashboard1::getUserValues(QString user)
// {
//     QString userName = user;
//     qDebug()<<"user"<<userName;
//     db1->addUser(userName);
// }

void dashboard1::BatteryLevel()
{
    if (battery > 0) {
        --battery;
        ui->progressBar->setValue(battery);
        qDebug() << "Battery level decreased. New level:" << battery;
    } else {
        qDebug() << "Battery is empty.";
    }
}

void dashboard1::EngineHrs()
{
    totalEngineHrs++;
    ui->enginneLabel_2->setText(QString::number(totalEngineHrs));
    qDebug()<<"Engine hrs:"<<totalEngineHrs;

}

void dashboard1::SpeedLevel()
{
    if(speed<200){
        ui->dial->setMinimum(0); // Minimum speed
        ui->dial->setMaximum(200); // Maximum speed
        ui->dial->setWrapping(true); // Allow wrapping around
        ui->dial->setNotchesVisible(true);
        ui->dial->setValue(speed);
        if(obj.getMode()=="Eco"){
            qDebug()<<"befor eco km"<<totalKm;
            speed +=10;
            qDebug()<<"update eco km"<<totalKm;
        }
        else{
            speed+=20;
        }
        qDebug()<<"Speed :"<<speed;

    }
}

void dashboard1::totalKmFun()
{
    // ui->totalKmLCD->show();
    ui->totalKmLCD->setDigitCount(7); // Display up to 6 digits
    // ui->totalKmLCD->setSegmentStyle(QLCDNumber::Flat);


        totalKm +=1;

        qDebug()<<"update km"<<totalKm;
     // Convert speed from km/h to km/s

    // Update RPM based on the speed
    rpm = calculateRPM(speed);
    qDebug()<<"rpm"<<rpm;
    // Update the QLCDNumber widgets
    ui->totalKmLCD->display(totalKm);
    ui->rpmLCD->display(rpm);
}

void dashboard1::resetValues(int engineHrs,int totalKm1)
{
    totalEngineHrs = engineHrs;
    totalKm = totalKm1;
    qDebug()<<"totalEn "<<totalEngineHrs<<" totlkm "<<totalKm;
}

// void dashboard1::on_toolButton_clicked()
// {
//     connect(leftTimer,&QTimer::timeout,this,&dashboard1::leftFun);
//     leftTimer->start();
// }

// void dashboard1::leftFun()
// {

// }


void dashboard1::on_leftButton_clicked()
{
    if(leftTimer && leftTimer->isActive()){
        leftTimer->stop();
        ui->leftLabel->setVisible(false);
    }
    if(rightTimer && rightTimer->isActive()){
        rightTimer->stop();
        ui->rightLabel->setVisible(false);
    }
    connect(leftTimer,&QTimer::timeout,this,&dashboard1::leftIndicator);
    leftTimer->setInterval(500);
    leftTimer->start();

}
void dashboard1::leftIndicator()
{

    ui->leftLabel->setVisible(!ui->leftLabel->isVisible());
}

void dashboard1::on_rightButton_clicked()
{
    if(rightTimer && rightTimer->isActive()){
        rightTimer->stop();
        ui->rightLabel->setVisible(false);
    }
    if(leftTimer && leftTimer->isActive()){
        leftTimer->stop();
        ui->leftLabel->setVisible(false);
    }
    connect(rightTimer,&QTimer::timeout,this,&dashboard1::rightIndicator);
    rightTimer->setInterval(500);
    rightTimer->start();
}

void dashboard1::rightIndicator()
{
    ui->rightLabel->setVisible(!ui->rightLabel->isVisible());
}

