#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMap>
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
    void showCity();

private slots:
    void on_saveButton_clicked();
    void on_imageButton_clicked();
    void on_downloadButton_clicked();
    void generatePdf();
    void updateMapHelper(QVector<QString> data);
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
