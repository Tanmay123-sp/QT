#include "usermodel.h"
#include<QDebug>
userModel::userModel() {}
userModel::userModel(const QString user,
                     const QString color,
                     const QString mode ):user(user),color(color),mode(mode){}

QString userModel::getuserName()
{
    qDebug()<<"dsd"<<user;
    return user;

}

QString userModel::getColor()
{
    return color;
}

QString userModel::getMode()
{
    return mode;
}
