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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateMapHelper(QVector<QString> data){
    qDebug() <<"Hellooooooo";
}

void MainWindow::on_saveButton_clicked()
{
    QString deviceName = ui->deviceNameT->toPlainText();
    QString serialNo = ui->serialNoT->toPlainText();
    QString assign = ui->assignT->toPlainText();
    QString location = ui->comboBox->currentText();
    QString img =ui->imageButton->text();

    emit updateMap({deviceName,serialNo,assign,location,img});
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
    painter.drawText(80, 80, "Data:");

    int y = 100;
    QString deviceName = ui->deviceNameT->toPlainText();
    for (const auto &pair : data->trackMap[deviceName]) {
        QString text = deviceName;
        QString text2 = pair.first;
        QString text3 = pair.second.first;
        QString text4 = pair.second.second.first;
        painter.drawText(100, y, text);
        painter.drawText(100,y+20,text2);
        painter.drawText(100,y+40,text3);
        painter.drawText(100,y+60,text4);
        qDebug()<<"xxxxxxxxxxxx"<<filenameFullPath;
        // Draw the uploaded image if it exists
        if (!filenameFullPath.isEmpty()) {
            QImage image(filenameFullPath);
            qDebug() << pair.second.second.second;
            qDebug() << image;
            if (!image.isNull()) {
                int newWidth = 200;  // Set desired width
                int newHeight = 200; // Set desired height (or use scaled height)

                QImage scaledImage = image.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                painter.drawImage(100, y + 100, scaledImage);
                y += scaledImage.height() + 20; // Adjust spacing after the image
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
