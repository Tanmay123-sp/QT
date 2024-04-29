#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QTimer>
#include"details1.h"
#include<QVector>
#include<vector>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(Details1& obj,QWidget *parent = nullptr);

    Details1 dobj;
    vector<QString> vec1;
    void updateCombo();
     // Dialog(Details1& obj) ;
~Dialog();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
