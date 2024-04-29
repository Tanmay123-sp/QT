#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include<QPainter>
#include<QtGui/QTextDocument>
#include<QFileDialog>
#include<QTextImageFormat>
#include "details1.h"
// #include<Qt5PrintSupport>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // QString deviceName = ui->deviceNameT->text();
    connect(ui->downloadButton, &QPushButton::clicked, this, &MainWindow::generatePdf);
    showCity();
     connect(this, &MainWindow::updateMap, data, &Details1::setMap);
    data->exportData();
    //connect(this, SIGNAL(update()), data, SLOT(dummy()));
     // connect(timer,SIGNAL(timeout()), this,SLOT(timerfun()));
  // timer->start(2000);

    //connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::newWindow);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateMapHelper(QVector<QString> data){
    qDebug() <<"Hellooooooo";
}

// void MainWindow::timerfun()
// {

//     static int colorIndex = 0;
//     QColor color;
//     switch (colorIndex) {
//     case 0:
//         color = Qt::green;
//         break;
//     case 1:
//         color = Qt::red;
//         break;
//     case 2:
//         color = Qt::blue;
//         break;
//     default:
//         colorIndex = 0;
//         color = Qt::green;
//         break;
//     }
//     setStyleSheet(QString("background-color: %1;").arg(color.name()));
//     colorIndex++;
// }

// void MainWindow::newWindow()
// {
//     d= new Dialog();
//     d->show();
//     connect(timer1,SIGNAL(timeout()),this,SLOT(timerfun1()));
//     timer1->start(2000);
// }
// void MainWindow::timerfun1()
// {
//     d->close();
// }



void MainWindow::on_saveButton_clicked()
{
    QString deviceName = ui->deviceNameT->toPlainText();
    QString serialNo = ui->serialNoT->toPlainText();
    QString assign = ui->assignT->toPlainText();
    QString location = ui->comboBox->currentText();
    QString img =ui->imageButton->text();

    emit updateMap({deviceName,serialNo,assign,location,img});

    // trackMap={
    //     {deviceName,
    //       {serialNo,
    //          {assign,
    //            {location,img}
    //       }}}};
}

void MainWindow::on_imageButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select An Image", QDir::homePath(), "Image Files (*.png *.jpg *.jpeg)");

    if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);

        filenameFullPath = fileName;
        QString justFileName = fileInfo.fileName();
        ui->imageButton->setText(justFileName);
    }
}


void MainWindow::on_downloadButton_clicked()
{
    generatePdf();
}
void MainWindow::generatePdf() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save pdf", "", "*.pdf");
    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QPainter painter;
    painter.begin(&printer);

    // Start drawing on the PDF
    painter.drawText(100, 100, "Data:");

    int y = 150;
    QString deviceName = ui->deviceNameT->toPlainText();
    for (const auto &pair : data->trackMap[deviceName]) {
        QString text = deviceName + "\n" + pair.first + "\n" + pair.second.first + "\n" + pair.second.second.first + "\n";
        painter.drawText(100, y, text);
        y += 50;
        qDebug() << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<filenameFullPath;
        // Draw the uploaded image if it exists
        if (!filenameFullPath.isEmpty()) {
            QImage image(filenameFullPath);
            qDebug() << pair.second.second.second;
            qDebug() << image;
            if (!image.isNull()) {
                painter.drawImage(100, y, image);
                y += image.height() + 20; // Adjust spacing after the image
            }
        }
    }

    painter.end();
}


void MainWindow:: showCity(){
    ui->comboBox->addItem("Pune");
    ui->comboBox->addItem("Hyderabad");
}



void MainWindow::on_pushButton_2_clicked()
{
    newWin= new Dialog(*data);
    newWin->show();
}


