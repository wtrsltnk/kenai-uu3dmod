#ifndef BOISSONNATSCENE_H
#define BOISSONNATSCENE_H

#include <QTextStream>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QWidget>
#include "triangulationitem.h"
#include "boundaryitem.h"
#include "pointsitem.h"

struct Potential {
	QVector<QPointF> pointsOnBoundary;
	QPointF pointNotOnBoundary;
	TriangleItem* triangle;
	float v;
	QPointF circleCenter;
	float circleRadius;
};

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

	TriangulationItem* triangulationItem;
	BoundaryItem* boundaryItem;
	PointsItem* pointsItem;
	QGraphicsItemGroup* centers;

protected:
	static bool calculateV(Potential& potential);
	static bool centerInTraingle(Potential& potential);
};

#endif // BOISSONNATSCENE_H
