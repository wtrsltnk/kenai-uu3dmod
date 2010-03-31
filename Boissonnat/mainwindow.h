#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "boissonnatscene.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	void loadScene();
	void stepToEnd();
	void step();
	void scaleUp();
	void scaleDown();

protected:
    void changeEvent(QEvent *e);
    BoissonnatScene boisScene;

private:
    Ui::MainWindow *ui;
	QTimer timer;
    
};

#endif // MAINWINDOW_H
