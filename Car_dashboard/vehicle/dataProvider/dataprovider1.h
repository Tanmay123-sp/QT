#ifndef DATAPROVIDER1_H
#define DATAPROVIDER1_H
#include"../database/database1.h"
#include<QTimer>
#include<QObject>
class dataProvider1:public QObject
{
    Q_OBJECT
private:
    // int battery = 100;
    QString userName;

public:
    //  int speed ;
    QString user;
    int totalEngineHrs;
    int totalKm;
     dataProvider1();
     ~dataProvider1();
    database1 *db1;
    // QTimer* batteryTimer = new QTimer(this);
    // QTimer* engineTimer = new QTimer(this);
    // QTimer* speedTimer = new QTimer(this);

    // int getBattery();
    bool getEngineHrsfromMain(int,int);
    QVector<userModel> getUserfromDataInfo();
    QVector<vehicleModel> getVehicleDatafromDB();
    void setVehicleDetails();
    void resetFun();
    userModel getLastUserInfofromDB();
    QString setUserName(QString);
    bool setCurrentUser(QString,QString,QString);

private slots:

    // void BatteryLevel();
    // void EngineHrs();
    // void SpeedLevel();

};

#endif // DATAPROVIDER1_H
