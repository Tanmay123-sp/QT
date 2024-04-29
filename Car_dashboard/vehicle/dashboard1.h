#ifndef DASHBOARD1_H
#define DASHBOARD1_H

#include <QDialog>
#include<QTimer>
#include<QVector>
#include<QLCDNumber>
#include"../models/usermodel.h"
#include"../models/vehiclemodel.h"
namespace Ui {
class dashboard1;
}

class dashboard1 : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard1(userModel LastUserObj,QVector<vehicleModel>getInfo,QWidget *parent = nullptr);
    ~dashboard1();

private:
    Ui::dashboard1 *ui;
    QVector<vehicleModel>vehicleInfo;
    QString user;
    QString color;
    QString mode;
public:
    int battery = 100;
    int totalEngineHrs;
    int totalKm;
    int speed;
    int rpm;
    userModel obj;
    void LastUserBG();

    // void updateSpeedometer(int speed);

    QTimer* batteryTimer = new QTimer(this);
    QTimer* engineTimer = new QTimer(this);
    QTimer* speedTimer = new QTimer(this);
    QTimer* leftTimer = new QTimer(this);
    QTimer* kmTimer = new QTimer(this);
    QTimer* rightTimer = new QTimer(this);
    int getBattery();
    int rpm1;
    // int getEngineHrs();
    QVector<QString>vecsetBg();
    void setBgfromMain(QString,QString,QString);

    // void resetFun();
    void getUserValues(QString);
    int calculateRPM(int speed);
protected:
    void closeEvent(QCloseEvent *event)override ;

signals:
    void exportEngKm(int,int);
    // void exportTotalKm(int);

private slots:

    void BatteryLevel();
    void EngineHrs();
    void SpeedLevel();
    void totalKmFun();
    void on_leftButton_clicked();
    void leftIndicator();

    void on_rightButton_clicked();
    void rightIndicator();

public slots:
    void resetValues(int,int);

    // void on_toolButton_clicked();
    // void leftFun();
};

#endif // DASHBOARD1_H
