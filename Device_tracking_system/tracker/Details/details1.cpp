#include "details1.h"
#include<QMessageBox>
#include <vector>
#include <QString>
#include <QMap>
using namespace std;

Details1::Details1(QObject *parent) : QObject(parent)
{
    myDatabase = QSqlDatabase::addDatabase("QSQLITE");
    myDatabase.setDatabaseName("myDatabase.db");

    if(myDatabase.open()){
        qDebug() << "Connection Successful.";
    }
    createTable();
}


Details1::~Details1()
{
    if (myDatabase.isOpen())
    {
        myDatabase.close();
    }
}

Details1::Details1(Details1 &obj){
    trackMap = obj.trackMap;
}
bool Details1::isOpen() const
{
    return myDatabase.isOpen();
}

bool Details1::createTable()
{
    bool success = true;
    QSqlQuery query;
    query.prepare("CREATE TABLE DeviceTracker("
                  "id INTEGER PRIMARY KEY, "
                  "devicename TEXT, "
                  "serialno TEXT, "
                  "assignedto TEXT, "
                  "location TEXT, "
                  "imgpath TEXT"
                  ");");

    if (!query.exec())
    {
        qDebug() << "tracker already exist.";
        success = false;
    }
    return success;
}

bool Details1::deletedata(const QString deviceName)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT FROM DeviceTracker WHERE deviceName =(:deviceName)");
    query.bindValue(":deviceName",deviceName);
    if(query.exec() && query.next()){
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM DeviceTracker WHERE deviceName =(:deviceName) ");
        queryDelete.bindValue(":deviceName",deviceName);
        success = queryDelete.exec();
        if(!success){
            qDebug()<<"remove device failed: "<<queryDelete.lastError();
            return false;
        }
}
    else{
        QMessageBox::warning(nullptr,"Error","Remove device failed!!!");
     return false;
    }
return true;
}


//inserting data into table
bool Details1::addData( const QString& deviceName, const QString& serialName, const QString& assignedTo, const QString& location, const QString& imgPath)
{
    bool success = false;

    if (!deviceName.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO DeviceTracker ( devicename, serialno, assignedto, location, imgpath) "
                         "VALUES ( :deviceName, :serialName, :assignedTo, :location, :imgPath)");
        queryAdd.bindValue(":deviceName", deviceName);
        queryAdd.bindValue(":serialName", serialName);
        queryAdd.bindValue(":assignedTo", assignedTo);
        queryAdd.bindValue(":location", location);
        queryAdd.bindValue(":imgPath", imgPath);

        if(queryAdd.exec())
        {
            qDebug() <<"data added successfully";
            success = true;

        }
        else
        {
            qDebug() << "add data failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add data failed: name cannot be empty";
    }
    return success;
}

vector<QString> Details1::exportCombo()
{
    vector<QString> vec;
    for (auto it = trackMap.begin(); it != trackMap.end(); ++it) {
        // Accessing the device name (key) explicitly
        QString deviceName = it.key();
        vec.push_back(deviceName);
    }
    return vec;
}

void Details1::exportData()
{
    QSqlQuery exportQuery;
    exportQuery.prepare("SELECT * From DeviceTracker;");
    if(exportQuery.exec())
    {
        while(exportQuery.next())
        {
            //QVector<std::pair<QString, std::pair<QString, std::pair<QString, QString>>>> v;
            QString key = exportQuery.value(1).toString();  // Assuming the first column is the key
            // Store data from each column in the vector
            QString col1 = exportQuery.value(2).toString();
            QString col2 = exportQuery.value(3).toString();
            QString col3 = exportQuery.value(4).toString();
            QString col4 = exportQuery.value(5).toString();

            qDebug()<<"data To Map";
            trackMap[key].push_back({col1,{col2,{col3 , col4}}});
        }
    }
}

void Details1::setMap(QVector<QString>v)
{
    trackMap[v[0]].push_back({v[1],{v[2],{v[3],v[4]}}});
    addData(v[0],v[1],v[2],v[3],v[4]);
}
