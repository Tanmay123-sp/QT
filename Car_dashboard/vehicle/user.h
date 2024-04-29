#ifndef USER_H
#define USER_H
#include"user.h"
#include <QDialog>
#include"adduser.h"
#include<QVector>
#include"../models/usermodel.h"
namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    user(){}
    explicit user(QVector<userModel>users,userModel LastUserobj, QWidget *parent = nullptr);
    ~user();
    adduser* au1;
    void addcolorCombo();
    void updateCombo();

private:
    Ui::user *ui;
    QVector<userModel>userInfo;
    userModel obj;
signals:
    void exportName1(QString);
    void exportBg(QString,QString,QString);
private slots:

    void addUserWin();
    void getUser(QString);

    void on_loadButton_clicked();
    QString radioButtonValues();
};

#endif // USER_H
