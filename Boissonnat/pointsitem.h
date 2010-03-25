#ifndef POINTSITEM_H
#define POINTSITEM_H

#include <QGraphicsItemGroup>
#include <QPointF>

class PointsItem : public QGraphicsItemGroup
{
public:
	PointsItem(const QVector<QPointF>& points);
	virtual ~PointsItem();

};

#endif // POINTSITEM_H
