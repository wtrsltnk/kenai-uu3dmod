#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog.h"
#include "QFile.h"
#include "QTextStream.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->ui->buttonLoad, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    ui->graphicsView->setScene(&this->boisScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::buttonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Input file"), "/home/Input/prac3-5", tr("Input Files (*.txt)"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    fileCounter = 0;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        processLine(line);
        fileCounter ++;
    }

}

void MainWindow::processLine(QString line){

//    int j = 0;
//
//
//    if(!fileCounter == 0){
//        while ((j = line.indexOf("< >", j)) != -1) {
//               //qDebug() << "Found < > tag at index position" << j;
//            ui->graphicsView->scene()->addText("" + j);
//               ++j;
//
//        }
//    }
}

