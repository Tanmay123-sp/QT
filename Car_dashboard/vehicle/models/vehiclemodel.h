#ifndef VEHICLEMODEL_H
#define VEHICLEMODEL_H
#include<QString>
class vehicleModel
{
public:
    vehicleModel();
    vehicleModel(const QString user,
                 const int engineHrs,
                 const int totalKm);
    QString getUser();
    int getEngineHrs();
    int getTotslKm();
private:
    QString user;
    int engineHrs;
    int totalKm;
};

#endif // VEHICLEMODEL_H
