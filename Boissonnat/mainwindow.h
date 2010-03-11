#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void buttonClicked();

protected:
    void changeEvent(QEvent *e);
    QGraphicsScene boisScene;
    void processLine(QString line);


private:
    Ui::MainWindow *ui;
    int fileCounter;
};

#endif // MAINWINDOW_H
