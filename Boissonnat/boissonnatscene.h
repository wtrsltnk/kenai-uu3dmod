#ifndef BOISSONNATSCENE_H
#define BOISSONNATSCENE_H

#include <QTextStream>
#include <QGraphicsScene>
#include <QWidget>

class BoissonnatScene : public QGraphicsScene
{
    Q_OBJECT

public:
    BoissonnatScene();
    virtual ~BoissonnatScene();

	void loadPointFile(QTextStream& in);

protected:
    QVector<QPointF> points;
	QGraphicsItem* boundary;

};

#endif // BOISSONNATSCENE_H
