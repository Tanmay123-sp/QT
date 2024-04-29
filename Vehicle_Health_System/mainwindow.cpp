#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QHBoxLayout"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    ap=new api;
    // QHeaderView *horizontalHeader = ui->FilterTable->horizontalHeader();
    // horizontalHeader->setStyleSheet("background-color: #ffffff; color: #000000;");

    QHeaderView* headerView = ui->FilterTable->horizontalHeader();
    QPalette palette = headerView->palette();
   palette.setBrush(QPalette::Window, QBrush(Qt::blue));  // Set the desired color
    headerView->setPalette(palette);

    QHeaderView *verticalHeader = ui->FilterTable->verticalHeader();
    verticalHeader->setStyleSheet("background-color: #ffffff; color: #000000;");

    load();

    timer = new QTimer();

    timer->setInterval(1000);
    timer->setSingleShot(false);

    connect(timer, &QTimer::timeout,this, &MainWindow::updateStatusValue);

    timer->start();

}


void MainWindow::load(){
    std::vector<Filter_details*> filterList = Filter_details::FilterList;

    int rowsCountFilter = filterList.size();
    ui->FilterTable->setRowCount(rowsCountFilter);

    for(int i=0; i<rowsCountFilter; i++){
        QTableWidgetItem *filterListItem =  new QTableWidgetItem(filterList[i]->getName());
        filterListItem->setTextAlignment(Qt::AlignCenter);
        ui->FilterTable->setItem(i,0,filterListItem);
        QDate currentDate = filterList[i]->getCurrentDate();
        QString dateString = currentDate.toString("dd-MM-yyyy");

        QTableWidgetItem *dateTableItem = new QTableWidgetItem(dateString);
        dateTableItem->setTextAlignment(Qt::AlignCenter);
        ui->FilterTable->setItem(i,2,dateTableItem);
        updateStatus(i, 1, "good");
    }

    std::vector<Fluid_details*> fluidList = Fluid_details::FluidList;

    int rowsCountFluid = fluidList.size();
    ui->FluidTable->setRowCount(rowsCountFluid);

        for(int i=0; i<rowsCountFluid; i++){
            QTableWidgetItem *fluidListItem =  new QTableWidgetItem(fluidList[i]->getName());
            fluidListItem->setTextAlignment(Qt::AlignCenter);
            ui->FluidTable->setItem(i,0,fluidListItem);
            QDate currentDate = fluidList[i]->getCurrentDate();
            QString dateString = currentDate.toString("dd-MM-yyyy");
            // qDebug()<<"fluid "<<dateString;

            QTableWidgetItem *dateTableItem = new QTableWidgetItem(dateString);
            dateTableItem->setTextAlignment(Qt::AlignCenter);
            ui->FluidTable->setItem(i,2,dateTableItem);

        updateStatus(i, 1, "good");
    }
}

void MainWindow::updateStatusValue(){
    if(count == 0) timer->stop();
    std::vector<Filter_details*>& filterList = Filter_details::FilterList;
    for(int i=0; i<filterList.size(); i++){
        // qDebug()<<filterList[i]->getStatus();
        filterList[i] = filterList[i]->setStatus(i+1);
        int healthLevel = filterList[i]->getStatus();
        // qDebug()<<healthLevel;

        if(healthLevel > 80) updateStatus(i, 1, "good");
        else if(healthLevel > 50 && healthLevel < 80) updateStatus(i, 1, "warning");
        else if(healthLevel > 0 && healthLevel < 50)updateStatus(i, 1, "critical");
    }

    std::vector<Fluid_details*>& fluidList = Fluid_details::FluidList;
    for(int i=0; i<fluidList.size(); i++){
        // qDebug()<<fluidList[i]->getStatus();
        fluidList[i] = fluidList[i]->setStatus(i+1);
        int healthLevel = fluidList[i]->getStatus();
        // qDebug()<<healthLevel;

        if(healthLevel > 80) updateStatus(i, 1, "good");
        else if(healthLevel > 50 && healthLevel < 80) updateStatus(i, 1, "warning");
        else if(healthLevel > 0 && healthLevel < 50)updateStatus(i, 1, "critical");
    }

    count--;
}

void MainWindow::updateStatus(int row, int column, QString status){
    QWidget *widget = new QWidget();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QLabel *label1 = new QLabel();
    QLabel *label2 = new QLabel();
    hBoxLayout->addWidget(label1);
    hBoxLayout->addWidget(label2);
    widget->setLayout(hBoxLayout);

    QWidget *widget1 = new QWidget();
    QHBoxLayout *hBoxLayout1 = new QHBoxLayout();
    QLabel *label1Fluid = new QLabel();
    QLabel *label2Fluid = new QLabel();
    hBoxLayout1->addWidget(label1Fluid);
    hBoxLayout1->addWidget(label2Fluid);
    widget1->setLayout(hBoxLayout1);

    ui->FilterTable->setCellWidget(row, column, widget);
    ui->FluidTable->setCellWidget(row,column,widget1);

    int width = 25;
    int height = 25;

    label1->setFixedSize(width, height);
    label1Fluid->setFixedSize(width,height);

    if(status == "good"){
        QPixmap pixmap(":/images/images/information.jpeg");
        label2->setText("Good ");
        label2Fluid->setText("Good");
        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);

            label1Fluid->setPixmap(pixmap);
            label1Fluid->setScaledContents(true);
        } else {
            label1->setText("Image not found");
            label1Fluid->setText("Image not found");
        }
    }

    if(status == "warning"){
        QPixmap pixmap(":/images/images/warning.jpeg");
        label2->setText("Warning ");

        label2Fluid->setText("Warning");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);

            label1Fluid->setPixmap(pixmap);
            label1Fluid->setScaledContents(true);

        } else {
            label1->setText("Image not found");
            label1Fluid->setText("Image not found");
        }
    }

    if(status == "critical"){
        QPixmap pixmap(":/images/images/critical.png");
        label2->setText("Critical ");
        label2Fluid->setText("Critical ");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);

            label1Fluid->setPixmap(pixmap);
            label1Fluid->setScaledContents(true);

        } else {
            label1->setText("Image not found");
            label1Fluid->setText("Image not found");
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FilterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_FluidButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

