#include "database1.h"
#include "../models/usermodel.h"

database1* database1::instance = nullptr;

database1::database1() {
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName("myDB.db");

    if(myDB.open()){
        qDebug()<<"Connection Successfull";
    }
    createTable();
    getEngineHrs();
    retriveUserInfo();
    retrieveUserInfoByVehicleUser();
}


database1::~database1(){
    if(myDB.isOpen()){
        myDB.close();
    }
}

database1 *database1::getInstance()
{
    if(instance == nullptr){
        instance = new database1; // Static instance created on first call
    // return instance;
    }
    return instance;
}

bool database1::isOpen() const
{
    return myDB.isOpen();
}

// bool database1::createTable()
// {
//     bool success = true;
//     QSqlQuery query;
//     query.prepare("CREATE TABLE myDB("
//                   "id INTEGER PRIMARY KEY, "
//                   "engineHrs TEXT, "
//                   "totalKm TEXT"
//                   ");");

//     if (!query.exec())
//     {
//         qDebug() << "tracker already exist.";
//         success = false;
//     }
//     return success;
// }

bool database1::createTable()
{
    bool success = true;
    QSqlQuery query;

    // Create the first table

    // Create the second table
    query.prepare("CREATE TABLE IF NOT EXISTS UserInfo("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "user TEXT UNIQUE, "
                  "color TEXT, "
                  "mode TEXT "
                  ");");

if (!query.exec())
{
    qDebug() << "Error creating UserInfo.";
    success = false;
}

query.prepare("CREATE TABLE IF NOT EXISTS VehicleInfo("
              "id INTEGER , "
              "user TEXT PRIMARY KEY, "
              "engineHrs TEXT, "
              "totalKm TEXT, "
              "FOREIGN KEY(user) REFERENCES UserInfo(user)"
              ");");


if (!query.exec())
{
    qDebug() << "Error creating VehicleInfo table."<<query.lastError().text();
    success = false;
}

return success;
}

userModel database1::retrieveUserInfoByVehicleUser() {
        // Construct the SQL query
    QSqlDatabase::database().transaction();
    userModel LastUser;
        QString queryStr = "SELECT * FROM UserInfo "
                           "INNER JOIN VehicleInfo ON UserInfo.user = VehicleInfo.user;";

        // Prepare the query
        QSqlQuery query;
        query.prepare(queryStr);

        // Execute the query
        if (query.exec()) {
            // Process the results if needed
            if (query.next()) {
                // Example: Retrieve columns from the UserInfo table
                int id = query.value(0).toInt(); // Assuming id is the first column
                const QString user = query.value(1).toString(); // Assuming user is the second column
                const QString color = query.value(2).toString(); // Assuming color is the third column
                const QString mode = query.value(3).toString(); // Assuming mode is the fourth column
                userModel user1(user,color,mode);
                LastUser = user1;
                // Process the retrieved data here
                // Example: Print the retrieved values
                qDebug() << "id:" << id << ", user:" << user << ", color:" << color << ", mode:" << mode;
            }
        } else {
            // Handle error if query execution fails
            qDebug() << "Error executing query:" << query.lastError().text();
            QSqlDatabase::database().rollback();
        }

        QSqlDatabase::database().commit();

        return LastUser;

    }



bool database1::addUser(QString userName)
{
    qDebug()<<"addUser";
    QSqlQuery query;
    query.prepare("INSERT INTO UserInfo(user, color, mode) VALUES (:userName, 'red', 'eco')");
    query.bindValue(":userName", userName);
    bool success = query.exec();

    if(success)
    {
        qDebug() << "User added successfully.";
    }
    else
    {
        qDebug() << "Error adding user:" << query.lastError().text();
    }
    return success;
}

// void database1::updateVehicleDetails(QString user,int engineHrs,int totalKm)
// {
//     QSqlQuery query;
//     query.prepare("INSERT INTO VehicleInfo(user,engineHrs,totalKm) VALUES (:user,:engineHrs,:totalKm)");
//     query.bindValue(":user",user);
//     query.bindValue(":engineHrs",engineHrs);
//     query.bindValue(":totalKm",totalKm);
//     if(query.exec())
//     {
//         qDebug()<<"user added Successfully";
//     }
//     else{
//         qDebug()<<"Error adding Vehicle:"<<query.lastError().text();
//     }
// }

bool database1::updateVehicleDetails( int engineHr, int totalkm) {
    QSqlQuery query;

    // Update all entries with the new user and values
    query.prepare("UPDATE VehicleInfo SET  engineHrs = engineHrs + :engineHr, totalKm = totalKm + :totalkm");
    // query.bindValue(":newUser", newUser);
    qDebug()<<"newww"<<totalkm;
    query.bindValue(":engineHr", engineHr);
    query.bindValue(":totalkm", totalkm);
    qDebug()<<engineHr<<totalkm;
    bool success = query.exec();
    if (success) {
        qDebug() << "Vehicle details updated successfully for all users";
    } else {
        qDebug() << "Error updating vehicle details:" << query.lastError().text();
    }
    return success;
}

bool database1::updateUserInfo(QString user, QString color, QString mode)
{
    qDebug()<<user<<color<<mode<<"hello";
    QSqlQuery query;
    qDebug() << "In the update user controller";

    query.prepare("UPDATE UserInfo SET user =:user,color = :color,mode= :mode WHERE user=:user");
        query.bindValue(":user",user);
        query.bindValue(":color",color);
        query.bindValue(":mode",mode);
        bool success = query.exec();
        if(success)
        {
            qDebug()<<"user updated Successfully";
        }
        else{
            qDebug()<<"Error updating userInfo:"<<query.lastError().text();
        }
        return success;
}

bool database1::updateLastUserInfo(QString user)
{
    qDebug()<<user<<"hello";
    QSqlQuery query;
    qDebug() << "In the update user controller";

    query.prepare("UPDATE VehicleInfo SET user =:user WHERE id=1");
    //query.bindValue(":mode",mode);
     query.bindValue(":user",user);
    // query.bindValue(":color",color);
     bool success = query.exec();
    if(success)
    {
        qDebug()<<"user updated Successfully";
    }
    else{
        qDebug()<<"Error updating userInfo:"<<query.lastError().text();
    }
    return success;
}



QVector<userModel> database1::retriveUserInfo()
{
    QVector<userModel>userList;
        // Prepare a query to retrieve values from the 'user' column in the 'UserInfo' table
        QSqlQuery query;
        query.prepare("SELECT * FROM UserInfo");

        // Execute the query
        if (!query.exec()) {
            qDebug() << "Error executing query: in retriveUserInfo" << query.lastError().text();
            return userList;
        }

        // Retrieve the values from the query result
        while (query.next()) {
            // QString user = query.value(0).toString(); // Assuming 'user' column is of type string
            userModel user(query.value("user").toString(),query.value("color").toString(),query.value("mode").toString());
            // Do something with the retrieved values
            // qDebug() << "User:" << user;

                userList.push_back(user);

            // u1.getuserName();

        }
        return userList;
}

QVector<vehicleModel> database1::retriveVehicleInfo()
{
    QVector<vehicleModel>vehicleList;
    // Prepare a query to retrieve values from the 'user' column in the 'UserInfo' table
    QSqlQuery query;
    query.prepare("SELECT * FROM VehicleInfo");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error executing query: in retriveVehicleInfo" << query.lastError().text();
        return vehicleList;
    }

    // Retrieve the values from the query result
    while (query.next()) {
        // QString user = query.value(0).toString(); // Assuming 'user' column is of type string
        vehicleModel vehicle(query.value("user").toString(),query.value("engineHrs").toInt(),query.value("totalKm").toInt());
        // Do something with the retrieved values
        // qDebug() << "User:" << user;

        vehicleList.push_back(vehicle);

        // u1.getuserName();

    }
    return vehicleList;
}

// bool database1::addData(const QString &user,const QString &engineHrs, const QString &totalKm)
// {
//     bool success = false;

//     if (!engineHrs.isEmpty())
//     {
//         QSqlQuery queryAdd;
//         queryAdd.prepare("INSERT INTO VehicleInfo (user, engineHrs,totalKm) "
//                          "VALUES (:user, :engineHrs,:totalKm)");
//         queryAdd.bindValue(":user", user);
//         queryAdd.bindValue(":engineHrs", engineHrs);
//         queryAdd.bindValue(":totalKm", totalKm);

//         if(queryAdd.exec())
//         {
//             qDebug() <<"data added successfully";
//             success = true;

//         }
//         else
//         {
//             qDebug() << "add data failed: " << queryAdd.lastError();
//         }
//     }
//     else
//     {
//         qDebug() << "add data failed: name cannot be empty";
//     }

//     return success;
// }


int database1::getEngineHrs()
{
//     QString selectQuery = "SELECT engineHrs FROM myDB LIMIT 1";
//     QSqlQuery query(selectQuery);
//     if(query.exec() && query.next()){
//         return query.value(0).toInt();
//     }else{
//         qDebug()<<"Error retrieving Engine Hrs: "<<query.lastError().text();
        return -1;
//     }
}

int database1::getTotalKm()
{
    QString selectQuery = "SELECT totalKm FROM myDB LIMIT 1";
    QSqlQuery query(selectQuery);
    if(query.exec() && query.next()){
        return query.value(1).toInt();
    }else{
        qDebug()<<"Error retrieving totalKm value:"<<query.lastError().text();
        return -1;
    }
}




