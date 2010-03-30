#ifndef BOUNDARYITEM_H
#define BOUNDARYITEM_H

#include <QGraphicsPolygonItem>

class BoundaryItem : public QGraphicsPolygonItem
{
public:
	BoundaryItem(const QVector<QPointF>& points);
	virtual ~BoundaryItem();

	void setBoundary(const QVector<QPointF>& points);

	QVector<QPointF>& getBoundaryPoints() { return this->boundaryPoints; }
	QGraphicsPolygonItem& getPolygon() { return this->polygon; }

private:
	QVector<QPointF> boundaryPoints;
	QGraphicsPolygonItem polygon;

};

#endif // BOUNDARYITEM_H
