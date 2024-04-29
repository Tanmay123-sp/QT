#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"dashboard1.h"
#include <QMainWindow>
#include"dataprovider1.h"
#include"user.h"
#include"adduser.h"
#include<QTimer>
#include<QVector>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    dataProvider1* dt1;
    dashboard1* dd1;
    user* uObj1;
    QTimer* timer1 ;
    QTimer* timer2 ;
    // QVector<QString> getUserInfofromDP();
    userModel getLastUserfromDP();


private:
    Ui::MainWindow *ui;
signals:
    void resetFun(int engineHrs,int totalKm);
private slots:
    void dashWin();
    void userWin();

    void timer1_fun();
    void timer2_fun();
    // void on_pushButton_clicked();
    void on_resetButton_clicked();
    void getUser1(QString);
    void getEngKmfromDash(int,int);
    void setBgfromUser(QString,QString,QString);

};
#endif // MAINWINDOW_H
