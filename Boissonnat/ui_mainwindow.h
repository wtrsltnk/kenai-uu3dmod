/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 11. Mar 22:08:41 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QPushButton *buttonLoad;
    QPushButton *buttonStep;
    QPushButton *buttonResult;
    QCheckBox *cbxTriangulation;
    QCheckBox *cbxBorder;
    QCheckBox *cbxPoints;
    QLabel *labelDisplay;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 10, 2);

        buttonLoad = new QPushButton(centralWidget);
        buttonLoad->setObjectName(QString::fromUtf8("buttonLoad"));
        buttonLoad->setFlat(false);

        gridLayout->addWidget(buttonLoad, 11, 0, 1, 1);

        buttonStep = new QPushButton(centralWidget);
        buttonStep->setObjectName(QString::fromUtf8("buttonStep"));

        gridLayout->addWidget(buttonStep, 11, 1, 1, 1);

        buttonResult = new QPushButton(centralWidget);
        buttonResult->setObjectName(QString::fromUtf8("buttonResult"));

        gridLayout->addWidget(buttonResult, 11, 2, 1, 1);

        cbxTriangulation = new QCheckBox(centralWidget);
        cbxTriangulation->setObjectName(QString::fromUtf8("cbxTriangulation"));

        gridLayout->addWidget(cbxTriangulation, 6, 2, 1, 1);

        cbxBorder = new QCheckBox(centralWidget);
        cbxBorder->setObjectName(QString::fromUtf8("cbxBorder"));

        gridLayout->addWidget(cbxBorder, 7, 2, 1, 1);

        cbxPoints = new QCheckBox(centralWidget);
        cbxPoints->setObjectName(QString::fromUtf8("cbxPoints"));

        gridLayout->addWidget(cbxPoints, 8, 2, 1, 1);

        labelDisplay = new QLabel(centralWidget);
        labelDisplay->setObjectName(QString::fromUtf8("labelDisplay"));

        gridLayout->addWidget(labelDisplay, 5, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Boissonnat", 0, QApplication::UnicodeUTF8));
        buttonLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        buttonStep->setText(QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8));
        buttonResult->setText(QApplication::translate("MainWindow", "Result", 0, QApplication::UnicodeUTF8));
        cbxTriangulation->setText(QApplication::translate("MainWindow", "Triangulation", 0, QApplication::UnicodeUTF8));
        cbxBorder->setText(QApplication::translate("MainWindow", "Border", 0, QApplication::UnicodeUTF8));
        cbxPoints->setText(QApplication::translate("MainWindow", "Points", 0, QApplication::UnicodeUTF8));
        labelDisplay->setText(QApplication::translate("MainWindow", "Display:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
