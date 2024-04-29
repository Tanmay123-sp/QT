#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<map>
#include<QString>
#include<QFileDialog>
#include<QPdfWriter>
#include<QtGui/QTextDocument>
#include<QFileDialog>
// #include<QTimer>
#include "details1.h"
#include"dialog.h"
#include "newwin.h"
using namespace std;

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
   // map<QString,pair<QString,pair<QString,pair<QString,QString>>>>trackMap;
    void showCity();
    // QTimer *timer=new QTimer(this);
    // QTimer *timer1=new QTimer(this);
    // QColor currentColor = Qt::green;
    //void setTimer(QTimer *newTimer);
    // Dialog *d;


private slots:
    void on_saveButton_clicked();

    void on_imageButton_clicked();

    void on_downloadButton_clicked();

    void generatePdf();

    void updateMapHelper(QVector<QString> data);
    // void timerfun();

    // void newWindow();

    // void timerfun1();

    void on_pushButton_2_clicked();

signals:
    void updateMap(QVector<QString>);
    void update();

private:
    Ui::MainWindow *ui;
    QString filenameFullPath;
    Details1 *data =new Details1();
    Dialog *newWin;
};
#endif // MAINWINDOW_H
