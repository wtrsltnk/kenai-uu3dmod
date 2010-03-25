#ifndef TRIANGULATIONITEM_H
#define TRIANGULATIONITEM_H

#include <QGraphicsItemGroup>
#include <QPointF>

class TriangulationItem : public QGraphicsItemGroup
{
public:
	TriangulationItem(const QVector<QPointF>& points);
	virtual ~TriangulationItem();

};

#endif // TRIANGULATIONITEM_H
