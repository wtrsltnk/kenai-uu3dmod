#include "boundaryitem.h"
#include "geompack.h"
#include <QPen>

BoundaryItem::BoundaryItem(const QVector<QPointF>& points)
{
	double* hullPoints = new double[points.size() * 2];
	int* hullIndices = new int[points.size()];

	for (int i = 0; i < points.size(); i++)
	{
		hullPoints[i * 2] = points.at(i).x();
		hullPoints[i * 2 + 1] = points.at(i).y();
	}

	int hullIndexCount;
	points_hull_2d(points.size(), hullPoints, &hullIndexCount, hullIndices);

	QPolygonF poly;
	for (int i = 0; i < hullIndexCount; i++)
		poly << points.at(hullIndices[i] - 1);

	this->setPolygon(poly);

	delete []hullPoints;
	delete []hullIndices;
}

BoundaryItem::~BoundaryItem()
{
}

void BoundaryItem::setBoundary(const QVector<QPointF>& points)
{
	QPolygonF poly;
	for (int i = 0; i < points.size(); i++)
		poly << points.at(i);

	this->setPolygon(poly);
}

