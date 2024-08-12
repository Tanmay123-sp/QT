#include "dialog.h"
#include "ui_dialog.h"
#include<QRadioButton>
using namespace std;

Dialog::Dialog(map<QString,pair<int,map<QString,int>>>&bookMap, map<QString,bool>&categoryMap, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Dialog),
    newbookMap(bookMap),
    newCategoryMap(categoryMap)
{
    ui->setupUi(this);
    connect(ui->radioButtonTech, &QRadioButton::clicked, this, &Dialog::on_radioButtonTech_clicked);
    connect(ui->radioButtonNonTech, &QRadioButton::clicked, this, &Dialog::on_radioButtonNonTech_clicked);

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_insertButton_clicked()
{
    QString bookName = ui->lineEdit1->text().trimmed();
    int bookCount = ui->lineEdit_2->text().toInt();
    bool bookCat = ui->radioButtonTech->isChecked();
    bool bookCat1 = ui->radioButtonNonTech->isChecked();
    if (!bookName.isEmpty() && bookCount > 0 && (bookCat || bookCat1)) {
        auto it = newbookMap.find(bookName);

        bool selectCat = bookCat ? bookCat : bookCat1;
        if (it != newbookMap.end()) {
            // Book found, update count inside the inner pair's map
            (it->second.first) += bookCount;

           // newCategoryMap[bookName] = selectCat;
            if(bookCat){
                on_radioButtonTech_clicked();
            }
            else{
                on_radioButtonNonTech_clicked();
            }
        } else {
            // Book not found, insert a new entry

            newbookMap[bookName]={bookCount,{}};
        }
        // newCategoryMap[bookName] = selectCat;
        emit booksUpdated(bookName, bookCount,selectCat);
    }

    ui->lineEdit1->clear();
    ui->lineEdit_2->clear();
}


void Dialog::on_deleteButton_clicked()
{
    QString bookName = ui->lineEdit1->text().trimmed();
    int bookCount = ui->lineEdit_2->text().toInt();

    if (!bookName.isEmpty()) {
        auto it = newbookMap.find(bookName);

        if (it != newbookMap.end() && bookCount < it->second.first) {
            // Book found, update count inside the inner pair's map
            it->second.first -= bookCount;
            emit booksUpdated_1(bookName, bookCount);
        }
    }

    ui->lineEdit1->clear();
    ui->lineEdit_2->clear();
}


void Dialog::on_radioButtonTech_clicked()
{
    QString bookName = ui->lineEdit1->text().trimmed();
    if(ui->radioButtonTech->isChecked()){
        newCategoryMap[bookName] = 1;
    }
}


void Dialog::on_radioButtonNonTech_clicked()
{
    QString bookName = ui->lineEdit1->text().trimmed();
    if( ui->radioButtonNonTech->isChecked()){
        newCategoryMap[bookName] = 0;
    }
}

