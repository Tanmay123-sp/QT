#include "adduser.h"
#include "ui_adduser.h"

adduser::adduser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adduser)
{
    ui->setupUi(this);
}

adduser::~adduser()
{
    delete ui;
}

void adduser::on_addButton_clicked()
{
    QString newUser = ui->userText->toPlainText();
    qDebug()<<newUser;
    emit exportName(newUser);
}
