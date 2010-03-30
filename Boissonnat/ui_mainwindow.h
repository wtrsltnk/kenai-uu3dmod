/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Mar 30 11:19:36 2010
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
#include <QtGui/QSpacerItem>
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
    QPushButton *scaleUp;
    QPushButton *scaleDown;
    QSpacerItem *verticalSpacer;
    QLabel *labelDisplay;
    QCheckBox *cbxTriangulation;
    QCheckBox *cbxBoundary;
    QCheckBox *cbxPoints;
    QPushButton *buttonLoad;
    QPushButton *buttonStep;
    QPushButton *buttonResult;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(614, 467);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 7, 2);

        scaleUp = new QPushButton(centralWidget);
        scaleUp->setObjectName(QString::fromUtf8("scaleUp"));
        scaleUp->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(scaleUp, 0, 2, 1, 1);

        scaleDown = new QPushButton(centralWidget);
        scaleDown->setObjectName(QString::fromUtf8("scaleDown"));
        scaleDown->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(scaleDown, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(192, 246, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        labelDisplay = new QLabel(centralWidget);
        labelDisplay->setObjectName(QString::fromUtf8("labelDisplay"));

        gridLayout->addWidget(labelDisplay, 3, 2, 1, 1);

        cbxTriangulation = new QCheckBox(centralWidget);
        cbxTriangulation->setObjectName(QString::fromUtf8("cbxTriangulation"));
        cbxTriangulation->setChecked(true);

        gridLayout->addWidget(cbxTriangulation, 4, 2, 1, 1);

        cbxBoundary = new QCheckBox(centralWidget);
        cbxBoundary->setObjectName(QString::fromUtf8("cbxBoundary"));
        cbxBoundary->setChecked(true);

        gridLayout->addWidget(cbxBoundary, 5, 2, 1, 1);

        cbxPoints = new QCheckBox(centralWidget);
        cbxPoints->setObjectName(QString::fromUtf8("cbxPoints"));
        cbxPoints->setChecked(true);

        gridLayout->addWidget(cbxPoints, 6, 2, 1, 1);

        buttonLoad = new QPushButton(centralWidget);
        buttonLoad->setObjectName(QString::fromUtf8("buttonLoad"));
        buttonLoad->setAutoDefault(false);
        buttonLoad->setDefault(false);
        buttonLoad->setFlat(false);

        gridLayout->addWidget(buttonLoad, 7, 0, 1, 1);

        buttonStep = new QPushButton(centralWidget);
        buttonStep->setObjectName(QString::fromUtf8("buttonStep"));

        gridLayout->addWidget(buttonStep, 7, 1, 1, 1);

        buttonResult = new QPushButton(centralWidget);
        buttonResult->setObjectName(QString::fromUtf8("buttonResult"));

        gridLayout->addWidget(buttonResult, 7, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 614, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);
        toolBar_4 = new QToolBar(MainWindow);
        toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Boissonnat", 0, QApplication::UnicodeUTF8));
        scaleUp->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        scaleDown->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        labelDisplay->setText(QApplication::translate("MainWindow", "Display:", 0, QApplication::UnicodeUTF8));
        cbxTriangulation->setText(QApplication::translate("MainWindow", "Triangulation", 0, QApplication::UnicodeUTF8));
        cbxBoundary->setText(QApplication::translate("MainWindow", "Boundary", 0, QApplication::UnicodeUTF8));
        cbxPoints->setText(QApplication::translate("MainWindow", "Points", 0, QApplication::UnicodeUTF8));
        buttonLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        buttonStep->setText(QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8));
        buttonResult->setText(QApplication::translate("MainWindow", "Result", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
        toolBar_4->setWindowTitle(QApplication::translate("MainWindow", "toolBar_4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
