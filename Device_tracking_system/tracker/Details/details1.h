#ifndef DETAILS1_H
#define DETAILS1_H
#include <QObject>
#include<QMap>
#include <QVector>
#include<vector>
#include<QString>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>

using namespace std;
class Details1:public QObject
{
    Q_OBJECT
public:
    explicit Details1(QObject *parent=nullptr);
    Details1(Details1& obj);
    QMap<QString,QVector<pair<QString,pair<QString,pair<QString,QString>>>>>trackMap;

    ~Details1();

    bool isOpen() const;

    bool createTable();

    bool deletedata(const QString);

    bool addData( const QString& deviceName, const QString& serialName, const QString& assignedTo, const QString& location, const QString& imgPath);

    vector<QString> exportCombo();

    QMap<QString,QVector<pair<QString,pair<QString,pair<QString,QString>>>>> getMap();

    void exportData();

public slots:
    void setMap(QVector<QString>);

private:
    QSqlDatabase myDatabase;

signals:
    void passData(QVector<QString>);
};


#endif // DETAILS1_H
