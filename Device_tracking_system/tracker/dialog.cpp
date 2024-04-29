#include "dialog.h"
#include "mainwindow.h"
#include "ui_dialog.h"
Dialog::Dialog(Details1& obj,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog),
    dobj(obj)

{
    ui->setupUi(this);
    vec1 = dobj.exportCombo();
    updateCombo();
}

// Dialog::Dialog(Details1& obj):dobj(obj){
//     vec1 = dobj.exportCombo();
//     updateCombo();
// }


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateCombo()
{
    qDebug()<<"gfgdfgfggfg";
    for(auto it:vec1)
    {

        ui->comboBox->addItem(it);
    }
}

void Dialog::on_pushButton_clicked()
{
    QString deviceName=ui->comboBox->currentText();
    dobj.deletedata(deviceName);
}

