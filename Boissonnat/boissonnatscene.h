#ifndef BOISSONNATSCENE_H
#define BOISSONNATSCENE_H

#include <QTextStream>
#include <QGraphicsScene>
#include "triangulationitem.h"
#include "boundaryitem.h"
#include "pointsitem.h"

struct Potential {
	QVector<QPointF> pointsOnBoundary;
	QPointF pointNotOnBoundary;
	TriangleItem* triangle;
	float v;
};

class BoissonnatScene : public QGraphicsScene
{
    Q_OBJECT

public:
    BoissonnatScene();
    virtual ~BoissonnatScene();

	void loadPointFile(QTextStream& in);
	bool step();

public slots:
	void triangulationStatusChanged(int state);
	void boundaryStatusChanged(int state);
	void pointsStatusChanged(int state);

protected:
	bool isPotential(Potential& potential);
	void calculateV(Potential& potential);
	bool centerInTraingle(Potential& potential);

protected:
	QVector<QPointF> points;

	TriangulationItem* triangulationItem;
	BoundaryItem* boundaryItem;
	PointsItem* pointsItem;

};

#endif // BOISSONNATSCENE_H
