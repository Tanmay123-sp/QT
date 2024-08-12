#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include "assign.h"
#include "details.h"
#include <QMainWindow>
#include <map>
#include<QString>
#include "stack.h"

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



private slots:
    void on_pushButton_clicked();
    void update_1(QString name,int count,bool selectCat);
    void update_2(QString name,int count);

    void on_assign_button_clicked();

    void on_detailsButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Dialog * di;
    Assign * ass;
    details *dt;
    stack *st;
    map<QString,pair<int,map<QString,int>>> bookMap;
    map<QString,bool>categoryMap;
    void add_Books();
    void count_Books();
    void updateTotalBooks();
    //void EachBookQty();
};
#endif // MAINWINDOW_H
