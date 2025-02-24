#include<gtest/gtest.h>
#include"../dataProvider/dataprovider1.h"
#include"mainwindow.h"
#include"user.h"
#include<QSignalSpy>
using namespace::testing;

class test1 : public ::testing ::Test{
protected:
    test1(){
        dpPtr = new dataProvider1();
    }
    ~test1(){
        delete dpPtr;
    }
    dataProvider1 *dpPtr;
};

TEST_F(test1,WhensetUserNameisCalledThenreturnUserName){

    QString name = dpPtr->setUserName("amann");
    QString ExpectedName ="amann";
    EXPECT_EQ(ExpectedName,name);
}


TEST_F(test1,WhengetLastUserInfofromDBisCalledThenCheckIfTrueisReturn){
    userModel* obj=new userModel("amann","red","Eco");

    EXPECT_EQ(obj->getuserName(),dpPtr->getLastUserInfofromDB().getuserName());
}


TEST_F(test1,WhengetEngineHrsfromMainisCalledThenCheckIfTrueisReturn){
    bool checkEngineHrsTotalKm = dpPtr->getEngineHrsfromMain(12,23);
    qDebug()<<checkEngineHrsTotalKm;
    EXPECT_TRUE(checkEngineHrsTotalKm);

    // bool checkIfUserExists = dsPtr->getUser("Tanmay");
}

TEST_F(test1,WhensetCurrentUserisCalledThenCheckIfTrueisReturn){
    bool checkCurrentUser = dpPtr->setCurrentUser("amann","red","Eco");
    qDebug()<<checkCurrentUser;
    EXPECT_TRUE(checkCurrentUser);

    // bool checkIfUserExists = dsPtr->getUser("Tanmay");
}

    // checkLastUserInfofromDB = dpPtr->getLastUserInfofromDB ();
    // qDebug()<<checkLastUserInfofromDB;
    // EXPECT_TRUE(checkLastUserInfofromDB);

    // bool checkIfUserExists = dsPtr->getUser("Tanmay");



// TEST(Test1,){

//     QString name = obj.setCurrentUser("tanmay","black","Eco");
//     QString ExpectedValue ="tanmay";
//     EXPECT_EQ(ExpectedValue,name);
// }

// TEST(Test1,hhk){
//     dataProvider1 obj;
//     QString name = obj.getUserfromDataInfo("tanmay","black","Eco");
//     QString ExpectedValue ="tanmay";
//     QString ExpectedValue1 ="black";
//     QString ExpectedValue2 ="Eco";
//     EXPECT_EQ(ExpectedValue,name);
// }

TEST(Test1,WhenexportName1){
    user obj;
    QSignalSpy spy(&obj,SIGNAL(exportName1(QString)));
    qDebug() << spy.count();
    EXPECT_EQ(spy.count(),9);
}
