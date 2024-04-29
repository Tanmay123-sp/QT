#include "vehiclemodel.h"

vehicleModel::vehicleModel() {}

vehicleModel::vehicleModel(const QString user,
             const int engineHrs,
             const int totalKm):user(user),engineHrs(engineHrs),totalKm(totalKm){}

QString vehicleModel::getUser()
{
    return user;
}

int vehicleModel::getEngineHrs()
{
    return engineHrs;
}

int vehicleModel::getTotslKm()
{
    return totalKm;
}

