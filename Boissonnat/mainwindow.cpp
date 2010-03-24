#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&this->boisScene);
    connect(this->ui->buttonLoad, SIGNAL(clicked()), this, SLOT(buttonClicked()));

	//ui->graphicsView->scale(100, 100);

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

void MainWindow::buttonClicked(){

    QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Input file"), "./Input/prac3-5", tr("Input Files (*.txt)"));


    this->boisScene.buttonClicked(fileName);
}


