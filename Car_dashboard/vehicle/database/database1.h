#ifndef DATABASE1_H
#define DATABASE1_H

#include<QObject>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include"../models/usermodel.h"
#include"../models/vehiclemodel.h"


class database1 :public QObject
{
    Q_OBJECT

private:
    //to make the class singleton we are making  constructor,copy constructor and assignment operator private
    database1();

    database1(const database1&);

    database1& operator=(const database1&);

public:
    ~database1();
    // Static member function to access the singleton instance

    static database1* getInstance();
    static database1* instance;
    bool isOpen() const;

    bool createTable();
    userModel retrieveUserInfoByVehicleUser();

    // bool deletedata(const QString);
    bool addUser(QString);
    bool updateVehicleDetails(int engineHrs,int totalKm);
    bool updateUserInfo(QString,QString,QString);
    bool updateLastUserInfo(QString);
    // bool addData(const QString& username,const QString& engineHrs,const QString& totalKm);
    QVector<userModel> retriveUserInfo();
    QVector<vehicleModel> retriveVehicleInfo();

    int getTotalKm();
    int getEngineHrs();
private:
    QSqlDatabase myDB;

};

#endif // DATABASE1_H
