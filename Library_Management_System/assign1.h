#ifndef ASSIGN1_H
#define ASSIGN1_H

#include <QDialog>

namespace Ui {
class assign1;
}

class assign1 : public QDialog
{
    Q_OBJECT

public:
    explicit assign1(QWidget *parent = nullptr);
    ~assign1();

private:
    Ui::assign1 *ui;
};

#endif // ASSIGN1_H
