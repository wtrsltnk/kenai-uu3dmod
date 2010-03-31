#include "boissonnatscene.h"
#include <iostream>
#include <QVector2D>
#include <math.h>

BoissonnatScene::BoissonnatScene()
	: triangulationItem(NULL), boundaryItem(NULL), pointsItem(NULL)
{
}

BoissonnatScene::~BoissonnatScene()
{
	this->removeItem(this->triangulationItem);
	delete this->triangulationItem;
	this->removeItem(this->boundaryItem);
	delete this->boundaryItem;
	this->removeItem(this->pointsItem);
	delete this->pointsItem;
}

bool BoissonnatScene::step()
{
	if (this->triangulationItem == NULL)
		return false;

	std::cout << "Step..";

	Potential largest;
	largest.v = 0;
	largest.triangle = NULL;

	for (int c = 0; c < this->triangulationItem->childItems().size(); c++)
	{
		Potential potential;
		TriangleItem* child = this->triangulationItem->getTriangle(c);
		if (child == NULL)
			continue;

		// Test of een van de punten in de triangle op de boundary ligt
		if (this->boundaryItem->getBoundaryPoints().contains(child->points[0]))
			potential.pointsOnBoundary.append(child->points[0]);
		else
			potential.pointNotOnBoundary = child->points[0];

		if (this->boundaryItem->getBoundaryPoints().contains(child->points[1]))
			potential.pointsOnBoundary.append(child->points[1]);
		else
			potential.pointNotOnBoundary = child->points[1];

		if (this->boundaryItem->getBoundaryPoints().contains(child->points[2]))
			potential.pointsOnBoundary.append(child->points[2]);
		else
			potential.pointNotOnBoundary = child->points[2];

		potential.triangle = child;
		if (this->calculateV(potential))
		{
			if (fabs(largest.v) < fabs(potential.v))
				largest = potential;
		}
	}
	if (largest.triangle != NULL)
	{
		// Carve triangle
		this->triangulationItem->removeTriangle(largest.triangle);
		this->boundaryItem->removeTriangle(&largest);
		return true;
	}
	else
	{
		std::cout << "Nothing to carve..." << std::endl;
	}

	return false;
}

bool BoissonnatScene::calculateV(Potential& potential)
{
	// Alleen als er twee punten op de boundary liggen gaan we door
	if (potential.pointsOnBoundary.size() != 2)
		return false;

	int boundaryPoint0Index = this->boundaryItem->getBoundaryPoints().indexOf(potential.pointsOnBoundary[0]);
	int boundaryPoint1Index = this->boundaryItem->getBoundaryPoints().indexOf(potential.pointsOnBoundary[1]);

	// Hier een controle om te zorgen dat de twee punten op de boundary wel na elkaar op de boundary liggen
	if ((abs(boundaryPoint0Index - boundaryPoint1Index) == 1) ||
		(boundaryPoint0Index == 0 && boundaryPoint1Index == this->boundaryItem->getBoundaryPoints().size()-1) ||
		(boundaryPoint1Index == 0 && boundaryPoint0Index == this->boundaryItem->getBoundaryPoints().size()-1))
	{
		QPointF centerBoundaryEdge = (potential.pointsOnBoundary.at(0) + potential.pointsOnBoundary.at(1)) / 2;
		QVector2D vDirection(centerBoundaryEdge.x() - potential.triangle->circleCenter.x(), centerBoundaryEdge.y() - potential.triangle->circleCenter.y());

		if (this->centerInTraingle(potential))
			potential.v = potential.triangle->radius - vDirection.length();
		else
			potential.v = potential.triangle->radius + vDirection.length();

		return true;
	}

	return false;
}

bool BoissonnatScene::centerInTraingle(Potential& potential)
{
	//(x2 - x1) * (py - y1) - (px - x1) * (y2 - y1);
	float orientationCenter = (potential.pointsOnBoundary.at(1).x() - potential.pointsOnBoundary.at(0).x()) *
			(potential.triangle->circleCenter.y() - potential.pointsOnBoundary.at(0).y()) - (potential.triangle->circleCenter.x() - potential.pointsOnBoundary.at(0).x()) *
			(potential.pointsOnBoundary.at(1).y() - potential.pointsOnBoundary.at(0).y());

	float orientationP3 = (potential.pointsOnBoundary.at(1).x() - potential.pointsOnBoundary.at(0).x()) *
			(potential.pointNotOnBoundary.y() - potential.pointsOnBoundary.at(0).y()) - (potential.pointNotOnBoundary.x() - potential.pointsOnBoundary.at(0).x()) *
			(potential.pointsOnBoundary.at(1).y() - potential.pointsOnBoundary.at(0).y());

	// Als zowel de center als het derde punt aan de zelfde kant van de boundary ligt, return true
	return ((orientationCenter > 0) == (orientationP3 > 0));
}

void BoissonnatScene::stepToEnd()
{
	std::cout << "Step to end..." << std::endl;
	while (step()) std::cout << "Stepping...";
	std::cout << "End" << std::endl;
}

// Loads points from a textstream and initializes the triangulation,
// boundary and points items correctly with the loaded points
void BoissonnatScene::loadPointFile(QTextStream& in)
{
	if (this->triangulationItem!= NULL)
		delete this->triangulationItem;

	if (this->boundaryItem != NULL)
		delete this->boundaryItem;

	if (this->pointsItem != NULL)
		delete this->pointsItem;

    this->clear();
    points.clear();

	while (!in.atEnd()) {
		QStringList elements = in.readLine().split(' ');
		if (elements.size() == 2)
		{
			QPointF point(elements[0].toFloat(), elements[1].toFloat());
			if (points.contains(point) == false)
				points.append(point	);
		}
    }

	this->triangulationItem = new TriangulationItem(points);
	addItem(this->triangulationItem);

	this->boundaryItem = new BoundaryItem(points);
	addItem(this->boundaryItem);

	this->pointsItem = new PointsItem(points);
	addItem(this->pointsItem);
}

// React to checking or unchecking the triangulation visibility
void BoissonnatScene::triangulationStatusChanged(int state)
{
	if (state == 0)
		removeItem(this->triangulationItem);
	else
		addItem(this->triangulationItem);
}

// React to checking or unchecking the boundary visibility
void BoissonnatScene::boundaryStatusChanged(int state)
{
	if (state == 0)
		removeItem(this->boundaryItem);
	else
		addItem(this->boundaryItem);
}

// React to checking or unchecking the points visibility
void BoissonnatScene::pointsStatusChanged(int state)
{
	if (state == 0)
		removeItem(this->pointsItem);
	else
		addItem(this->pointsItem);
}
