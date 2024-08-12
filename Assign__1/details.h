#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include<map>
using namespace std;

namespace Ui {
class details;
}

class details : public QDialog
{
    Q_OBJECT

public:
    explicit details(map<QString,pair<int,map<QString,int>>>&bookMap,map<QString,bool>&categoryMap,QWidget *parent = nullptr);
    ~details();

private:
    Ui::details *ui;
    map<QString,pair<int,map<QString,int>>> &newBookMap;
    map<QString,bool>&newCategoryMap;
};

#endif // DETAILS_H
