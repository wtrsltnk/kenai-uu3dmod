#include "pointsitem.h"
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

PointsItem::PointsItem(const QVector<QPointF>& points)
{
	// Add a ellipse for every point in the point vector
	for (int i = 0; i < points.size(); i++)
	{
		QPointF point = points.at(i);
		QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(point.x()-1, point.y()-1, 2, 2);
		ellipse->setPen(QPen(QColor(55, 100, 255)));
		this->addToGroup(ellipse);
	}
}

PointsItem::~PointsItem()
{
}
