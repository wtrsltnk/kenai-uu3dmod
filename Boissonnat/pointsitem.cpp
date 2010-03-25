#include "pointsitem.h"
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

PointsItem::PointsItem(const QVector<QPointF>& points)
{
	for (int i = 0; i < points.size(); i++)
	{
		QPointF point = points.at(i);
		QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(point.x()-1, point.y()-1, 2, 2);
		this->addToGroup(ellipse);
	}
}

PointsItem::~PointsItem()
{
}
