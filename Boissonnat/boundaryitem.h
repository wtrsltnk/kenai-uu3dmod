#ifndef BOUNDARYITEM_H
#define BOUNDARYITEM_H

#include <QGraphicsPolygonItem>
#include <QGraphicsItemGroup>
#include "triangulationitem.h"

struct Potential;

class BoundaryItem : public QGraphicsItemGroup
{
public:
	BoundaryItem(const QVector<QPointF>& points);
	virtual ~BoundaryItem();

	void removeTriangle(Potential* item);

	QVector<QPointF>& getBoundaryPoints() { return this->boundaryPoints; }

private:
	QVector<QPointF> boundaryPoints;
	QGraphicsPolygonItem* polygon;

};

#endif // BOUNDARYITEM_H
