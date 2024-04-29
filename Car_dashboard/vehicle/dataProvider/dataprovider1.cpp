#include "dataprovider1.h"

dataProvider1::dataProvider1() {

    db1 = database1::getInstance();
    // totalEngineHrs = 0;
    // speed = 0;
    // connect(batteryTimer, &QTimer::timeout,this,&dataProvider1::BatteryLevel);
    // batteryTimer->start(20000);

    // connect(engineTimer,&QTimer::timeout,this,&dataProvider1::EngineHrs);
    // engineTimer->start(5000);

    // connect(speedTimer,&QTimer::timeout,this,&dataProvider1::SpeedLevel);
    // speedTimer->start(3000);
}

dataProvider1::~dataProvider1(){
    // delete db1;
}
QString dataProvider1::setUserName(QString user)
{
    userName = user;
    qDebug()<<"user"<<userName;
    db1->addUser(userName);
    return userName;
}

bool dataProvider1::setCurrentUser(QString user, QString color, QString mode)
{
    bool success1 = db1->updateUserInfo(user,color,mode);
    bool success2 = db1->updateLastUserInfo(user);

    if((success1 && success2) != true){
        return false;
    }
    return true;
}

bool dataProvider1::getEngineHrsfromMain(int EngineHrs,int totalKm)
{

    totalEngineHrs = EngineHrs;
    totalKm = totalKm;
    qDebug()<<totalEngineHrs<<"dp"<<totalKm;
    return db1->updateVehicleDetails(totalEngineHrs,totalKm);
    // setVehicleDetails();
}

QVector<userModel> dataProvider1::getUserfromDataInfo()
{
    return db1->retriveUserInfo();
}

QVector<vehicleModel> dataProvider1::getVehicleDatafromDB()
{
    return db1->retriveVehicleInfo();
}

void dataProvider1::setVehicleDetails()
{
    qDebug()<<" data provider"<<totalEngineHrs<<" "<<totalKm;
    // db1->updateVehicleDetails(totalEngineHrs,totalKm);

}

// void dataProvider1::getUserfromDataInfo()
// {
//     db1->retriveUserInfo();
// }
// int dataProvider1::getBattery()
// {
//     return battery;
// }

void dataProvider1::resetFun()
{
    // speed=0;
}

userModel dataProvider1::getLastUserInfofromDB()
{
    return db1->retrieveUserInfoByVehicleUser();
}


