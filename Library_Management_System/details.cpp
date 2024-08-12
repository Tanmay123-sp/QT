#include "details.h"
#include "ui_details.h"

details::details(map<QString,pair<int,map<QString,int>>>&bookMap,map<QString,bool>&categoryMap,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::details),
    newBookMap(bookMap),
    newCategoryMap(categoryMap)

{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(10);
    ui->tableWidget_2->setRowCount(10);
    int row = 0;
    for (const auto &it : newBookMap){
        int avail = -1;
         for (const auto &it2 : it.second.second){
            if(avail == -1)
             {
                 avail = it.second.first - it2.second;
             }
            else
            {
                avail -= it2.second;
            }
            //int remaining_books = (it.second.first)-(it2.second);
            ui->tableWidget->setItem(row,0, new QTableWidgetItem(it.first));
            ui->tableWidget->setItem(row,1, new QTableWidgetItem(QString::number(it.second.first)));
             ui->tableWidget->setItem(row,2, new QTableWidgetItem(it2.first));
             ui->tableWidget->setItem(row,3, new QTableWidgetItem(QString::number(it2.second)));
             ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString::number(avail)));
             row++;
         }

    }

    int row2 =0;
    for(const auto &it : newCategoryMap){
        ui->tableWidget_2->setItem(row2,0, new QTableWidgetItem(it.first));

        int categoryValue = it.second ;
        if(it.second == true)
        {
            ui->tableWidget_2->setItem(row2, 1, new QTableWidgetItem("Tech"));
        }
        else
        {
            ui->tableWidget_2->setItem(row2, 1, new QTableWidgetItem("Non Tech"));

        }

        // ui->tableWidget_2->setItem(row2,1, new QTableWidgetItem(it.second.toInt()));
        row2++;
    }

}

details::~details()
{
    delete ui;
}
