#include "assign1.h"
#include "ui_assign1.h"

assign1::assign1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::assign1)
{
    ui->setupUi(this);
}

assign1::~assign1()
{
    delete ui;
}
