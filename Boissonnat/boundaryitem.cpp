#include "boundaryitem.h"
#include "geompack.h"
#include "boissonnatscene.h"
#include <QPen>
#include <QGraphicsPolygonItem>

// Tijdens contructie van de boundary item wordt de convex hull gebruikt als begin boundary
BoundaryItem::BoundaryItem(const QVector<QPointF>& points)
	: polygon(NULL)
{
	// Initializeer de array's voor de convex hull punten en indices
	double* hullPoints = new double[points.size() * 2];
	int* hullIndices = new int[points.size()];

	// Kopieer de punten uit de Qt points vector naar de hullPoints double array
	for (int i = 0; i < points.size(); i++)
	{
		hullPoints[i * 2] = points.at(i).x();
		hullPoints[i * 2 + 1] = points.at(i).y();
	}

	// Vraag een lijst met van punt indices op die op de convex hull liggen
	int hullIndexCount;
	points_hull_2d(points.size(), hullPoints, &hullIndexCount, hullIndices);

	// De initiele boundary is de convex hull
	QPolygonF poly;
	for (int i = 0; i < hullIndexCount; i++)
	{
		boundaryPoints.append(points.at(hullIndices[i] - 1));
		poly << points.at(hullIndices[i] - 1);
	}

	// Voeg de polygon toe aan de scene met een prachtig(..) kleurtje
	this->polygon = new QGraphicsPolygonItem(poly);
	this->polygon->setPen(QPen(QColor(255, 0, 0), 2.0f));
	this->addToGroup(this->polygon);

	// Voorkom memoryleaks, clean-up!
	delete []hullPoints;
	delete []hullIndices;
}

BoundaryItem::~BoundaryItem()
{
}

void BoundaryItem::removeTriangle(Potential* item)
{
	int index = 0;
	int boundaryPoint0Index = this->boundaryPoints.indexOf(item->pointsOnBoundary[0]);
	int boundaryPoint1Index = this->boundaryPoints.indexOf(item->pointsOnBoundary[1]);

	// Kies een index waar je de nieuwe vertex op de boundary toevoegd. Zorg dat deze achteraan toegevoegd
	// wordt als de vertex tussen de laatste en de eerste moet komen.
	if ((boundaryPoint0Index == 0 && boundaryPoint1Index == this->boundaryPoints.size() - 1) ||
		(boundaryPoint1Index == 0 && boundaryPoint0Index == this->boundaryPoints.size() - 1))
		index = this->boundaryPoints.size();
	else if (boundaryPoint0Index > boundaryPoint1Index)
		index = boundaryPoint0Index;
	else
		index = boundaryPoint1Index;

	this->boundaryPoints.insert(index, item->pointNotOnBoundary);

	QPolygonF poly;

	// Maak een nieuwe polygon aan van de nieuw lijst punten op de boundary
	for (int i = 0; i < this->boundaryPoints.size(); i++)
		poly << this->boundaryPoints[i];
	this->polygon->setPolygon(poly);
}

