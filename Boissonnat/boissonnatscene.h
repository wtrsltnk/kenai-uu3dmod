#ifndef BOISSONNATSCENE_H
#define BOISSONNATSCENE_H

#include <QGraphicsScene>
#include <QWidget>

class BoissonnatScene : public QGraphicsScene
{
    Q_OBJECT

public:
    BoissonnatScene();
    virtual ~BoissonnatScene();
    void buttonClicked(QString fileName);


protected:

    void processLine(QString line);
    QVector<QPointF> points;

private:

    int fileCounter;

};

#endif // BOISSONNATSCENE_H
