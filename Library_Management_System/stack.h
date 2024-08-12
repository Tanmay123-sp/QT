#ifndef STACK_H
#define STACK_H

#include <QDialog>
#include<map>
using namespace std;
namespace Ui {
class stack;
}

class stack : public QDialog
{
    Q_OBJECT

public:
    explicit stack(map<QString,bool>&categoryMap,QWidget *parent = nullptr);
    ~stack();

private slots:
    void on_radioButtonTech_clicked();

    void on_radioButtonNonTech_clicked();

private:
    Ui::stack *ui;
    map<QString,bool>&newcategoryMap;
};

#endif // STACK_H
