#ifndef BOUNDARYITEM_H
#define BOUNDARYITEM_H

#include <QGraphicsPolygonItem>

class BoundaryItem : public QGraphicsPolygonItem
{
public:
	BoundaryItem(const QVector<QPointF>& points);
	virtual ~BoundaryItem();

	void setBoundary(const QVector<QPointF>& points);

private:
	QGraphicsPolygonItem polygon;

};

#endif // BOUNDARYITEM_H
