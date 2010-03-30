#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->buttonLoad->setFocus();
    ui->graphicsView->setScene(&this->boisScene);
	connect(this->ui->buttonLoad, SIGNAL(clicked()), this, SLOT(loadScene()));
	connect(this->ui->cbxTriangulation, SIGNAL(stateChanged(int)), &this->boisScene, SLOT(triangulationStatusChanged(int)));
	connect(this->ui->cbxBoundary, SIGNAL(stateChanged(int)), &this->boisScene, SLOT(boundaryStatusChanged(int)));
	connect(this->ui->cbxPoints, SIGNAL(stateChanged(int)), &this->boisScene, SLOT(pointsStatusChanged(int)));
	connect(this->ui->scaleUp, SIGNAL(clicked()), this, SLOT(scaleUp()));
	connect(this->ui->scaleDown, SIGNAL(clicked()), this, SLOT(scaleDown()));
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

void MainWindow::loadScene(){

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Input file"), "./", tr("Input Files (*.txt)"));
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&file);
	
	/// Skip the first line with the pointcount
	in.readLine();

	this->boisScene.loadPointFile(in);
}

void MainWindow::scaleUp()
{
	this->ui->graphicsView->scale(2, 2);
}

void MainWindow::scaleDown()
{
	this->ui->graphicsView->scale(0.5, 0.5);
}


