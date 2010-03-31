#include "boundaryitem.h"
#include "geompack.h"
#include "boissonnatscene.h"
#include <QPen>

BoundaryItem::BoundaryItem(const QVector<QPointF>& points)
	: polygon(NULL)
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
	{
		boundaryPoints.append(points.at(hullIndices[i] - 1));
		poly << points.at(hullIndices[i] - 1);
	}

	this->polygon = new QGraphicsPolygonItem(poly);
	this->polygon->setPen(QPen(QColor(255, 0, 0), 2.0f));
	this->addToGroup(this->polygon);

	delete []hullPoints;
	delete []hullIndices;
}

BoundaryItem::~BoundaryItem()
{
}

void BoundaryItem::removeTriangle(Potential* item)
{
	int boundaryPoint0Index = this->boundaryPoints.indexOf(item->pointsOnBoundary[0]);
	int boundaryPoint1Index = this->boundaryPoints.indexOf(item->pointsOnBoundary[1]);

	int index = 0;
	if ((boundaryPoint0Index == 0 && boundaryPoint1Index == this->boundaryPoints.size() - 1) ||
		(boundaryPoint1Index == 0 && boundaryPoint0Index == this->boundaryPoints.size() - 1))
		index = this->boundaryPoints.size();
	else if (boundaryPoint0Index > boundaryPoint1Index)
		index = boundaryPoint0Index;
	else
		index = boundaryPoint1Index;

	this->boundaryPoints.insert(index, item->pointNotOnBoundary);

	if (this->polygon != NULL)
	{
		this->removeFromGroup(this->polygon);
		delete this->polygon;
	}
	QPolygonF poly;
	for (int i = 0; i < this->boundaryPoints.size(); i++)
		poly << this->boundaryPoints[i];

	this->polygon = new QGraphicsPolygonItem(poly);
	this->polygon->setPen(QPen(QColor(255, 0, 0), 2.0f));
	this->addToGroup(this->polygon);
}

