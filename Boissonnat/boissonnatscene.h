#ifndef BOISSONNATSCENE_H
#define BOISSONNATSCENE_H

#include <QTextStream>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QWidget>

class BoissonnatScene : public QGraphicsScene
{
    Q_OBJECT

public:
    BoissonnatScene();
    virtual ~BoissonnatScene();

	void loadPointFile(QTextStream& in);

public slots:
	bool step();
	void stepToEnd();

	void triangulationStatusChanged(int state);
	void boundaryStatusChanged(int state);
	void pointsStatusChanged(int state);

protected:
	QVector<QPointF> points;

	QGraphicsItem* triangulationItem;
	QGraphicsPolygonItem* boundaryItem;
	QGraphicsItem* pointsItem;

};

#endif // BOISSONNATSCENE_H
