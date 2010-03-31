#ifndef BOUNDARYITEM_H
#define BOUNDARYITEM_H

#include <QGraphicsItemGroup>
#include "triangulationitem.h"

// Forward declaration van de Potential structure, header staat in de cpp
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
