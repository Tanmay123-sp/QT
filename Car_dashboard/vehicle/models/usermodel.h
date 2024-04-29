#ifndef USERMODEL_H
#define USERMODEL_H
#include<QObject>
#include<QString>
class userModel
{

public:
    userModel();
    userModel(const QString user,
              const QString color,
              const QString mode );
    QString getuserName();
    QString getColor();
    QString getMode();

private:
    QString user;
    QString color;
    QString mode;
};

#endif // USERMODEL_H
