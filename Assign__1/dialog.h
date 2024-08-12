#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<map>

using namespace std;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(map<QString,pair<int,map<QString,int>>>&bookMap,map<QString,bool>&categoryMap, QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
   map<QString,pair<int,map<QString,int>>>&newbookMap;
   map<QString,bool>&newCategoryMap;
   void updateCategory();

private slots:
    void on_insertButton_clicked();

    void on_deleteButton_clicked();

    void on_radioButtonTech_clicked();

    void on_radioButtonNonTech_clicked();

signals:
    void booksUpdated(QString , int,bool);
    void booksUpdated_1(QString,int);

};

#endif // DIALOG_H
