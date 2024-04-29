#include "user.h"
#include "ui_user.h"

user::user(QVector<userModel>users,userModel LastUserobj, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::user),
    userInfo(users),
    obj(LastUserobj)

{
    ui->setupUi(this);
    connect(ui->addUserButton,&QPushButton::clicked,this,&user::addUserWin);
    addcolorCombo();
    updateCombo();
    ui->userCombo->setCurrentText(obj.getuserName());
    ui->colorCombo->setCurrentText(obj.getColor());
    if(obj.getMode()=="Eco"){
        ui->Eco_radioButton->setChecked(true);
    }
    else if(obj.getMode()=="Sport"){
        ui->Sport_radioButton->setChecked(true);
    }
    connect(ui->Eco_radioButton,&QRadioButton::clicked,this,&user::radioButtonValues);
    connect(ui->Sport_radioButton,&QRadioButton::clicked,this,&user::radioButtonValues);
}

user::~user()
{
    delete ui;
}

void user::addcolorCombo()
{
    ui->colorCombo->addItem("black");
    ui->colorCombo->addItem("blue");
    ui->colorCombo->addItem("grey");
}

void user::updateCombo()
{
    for(auto i: userInfo){
        qDebug()<<i.getuserName();
        QString username = i.getuserName();
        ui->userCombo->addItem(username);
    }
}

void user::addUserWin()
{
    au1 = new adduser(this);
    au1->show();
    connect(au1,&adduser::exportName,this,&user::getUser);
}

void user::getUser(QString name)
{
    // updateCombo(name);
    emit exportName1(name);
    // return name;
    // qDebug()<<name;
}

void user::on_loadButton_clicked()
{
    QString uName = ui->userCombo->currentText();
    QString color = ui->colorCombo->currentText();
    QString mode = radioButtonValues();
    emit exportBg(uName,color,mode);
}

QString user::radioButtonValues()
{
    if(ui->Eco_radioButton->isChecked()){
        return ui->Eco_radioButton->text();
    }
    else if(ui->Sport_radioButton->isChecked()){
            return ui->Sport_radioButton->text();
        }
    return {};
}

