#ifndef ASSIGN_H
#define ASSIGN_H

#include <QDialog>
#include <map>
using namespace std;
namespace Ui {
class Assign;
}

class Assign : public QDialog
{
    Q_OBJECT

public:
    explicit Assign(map<QString, pair<int, map<QString, int>>> &bookMap,
                    map<QString, bool> &categoryMap,
                    QWidget *parent = nullptr);
    ~Assign();

private slots:
    void on_pushButton_clicked();

    //void on_radioButton_clicked();

    void on_radioButton_Tech_clicked();

    void on_radioButtonAll_clicked();

    void on_radioButton_NonTech_clicked();

private:
    Ui::Assign *ui;
    map<QString, pair<int, map<QString, int>>> &newbookMap;
    map<QString, bool> &newCategoryMap;
    void add_Books();
    void add_user();
    void add_qty();
};

#endif // ASSIGN_H
