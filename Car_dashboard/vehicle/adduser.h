#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>

namespace Ui {
class adduser;
}

class adduser : public QDialog
{
    Q_OBJECT

public:
    explicit adduser(QWidget *parent = nullptr);
    ~adduser();

signals:
    void exportName(QString);

private slots:
    void on_addButton_clicked();

private:
    Ui::adduser *ui;
};

#endif // ADDUSER_H
