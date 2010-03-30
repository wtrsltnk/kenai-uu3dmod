#include "boissonnatscene.h"
#include <iostream>
#include <QVector2D>
#include <math.h>

BoissonnatScene::BoissonnatScene()
	: triangulationItem(NULL), boundaryItem(NULL), pointsItem(NULL), centers(NULL)
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
	this->removeItem(this->centers);
	delete this->centers;
}

bool BoissonnatScene::step()
{
	std::cout << "Step!" << std::endl;

	Potential largest;
	largest.v = 0;
	largest.triangle = NULL;

	if (this->centers != NULL)
	{
		this->removeItem(this->centers);
		delete this->centers;
	}
	this->centers = new QGraphicsItemGroup();
	this->addItem(this->centers);
	for (int c = 0; c < this->triangulationItem->childItems().size(); c++)
	{
		Potential potential;
		TriangleItem* child = dynamic_cast <TriangleItem*> (this->triangulationItem->childItems().at(c));
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

		// Als er twee punten op de boundary liggen, is de triangle een potentieel op te verwijderen
		potential.triangle = child;
		if (BoissonnatScene::calculateV(potential))
		{
			this->centers->addToGroup(new QGraphicsEllipseItem(potential.circleCenter.x() - potential.circleRadius, potential.circleCenter.y() - potential.circleRadius, potential.circleRadius * 2, potential.circleRadius * 2));
			if (fabs(largest.v) < fabs(potential.v))
				largest = potential;
		}
	}
	if (largest.triangle != NULL)
	{
		// Carve triangle
	}
	return false;
}

bool BoissonnatScene::calculateV(Potential& potential)
{
	if (potential.pointsOnBoundary.size() != 2)
		return false;

//	QPointF A = potential.triangle->polygon().at(0);
//	QPointF B = potential.triangle->polygon().at(1);
//	QPointF C = potential.triangle->polygon().at(2);
//
//	// Bereken de circumcenter (http://en.wikipedia.org/wiki/Circumscribed_circle#Cartesian_coordinates)
//	float D = (2 * (A.x() * (B.y() - C.y()) + B.x() * (C.y() - A.y()) + C.x() * (A.y() - B.y())));
//	std::cout << "D: " << D << std::endl;
//	if (D <= 0.000001)
//		return false;
//
//	float Ax2 = (A.x() * A.x());
//	float Ay2 = (A.y() * A.y());
//	float Bx2 = (B.x() * B.x());
//	float By2 = (B.y() * B.y());
//	float Cx2 = (C.x() * C.x());
//	float Cy2 = (C.y() * C.y());
//	std::cout << "Ax2: " << Ax2 << std::endl;
//	std::cout << "Ay2: " << Ay2 << std::endl;
//	std::cout << "Bx2: " << Bx2 << std::endl;
//	std::cout << "By2: " << By2 << std::endl;
//	std::cout << "Cx2: " << Cx2 << std::endl;
//	std::cout << "Cy2: " << Cy2 << std::endl;
//
//	float centerX = ((Ay2 + Ax2) * (B.y() - C.y()) + (By2 + Bx2) * (C.y() - A.y()) + (Cy2 + Cx2) * (A.y() - B.y())) / D;
//	float centerY = ((Ay2 + Ax2) * (B.x() - C.x()) + (By2 + Bx2) * (C.x() - A.x()) + (Cy2 + Cx2) * (A.x() - B.x())) / D;
//
//	QVector2D radius(centerX - A.x(), centerY - A.y());
//	potential.circleCenter = QPointF(centerX, centerY);
//	potential.circleRadius = radius.length();
//
	QPointF centerOnBoundary = (potential.pointsOnBoundary.at(0) + potential.pointsOnBoundary.at(1)) / 2;

	QVector2D vDirection(centerOnBoundary.x() - potential.triangle->circleCenter.x(), centerOnBoundary.y() - potential.triangle->circleCenter.y());

	if (centerInTraingle(potential))
	{
		potential.v = potential.circleRadius - vDirection.length();
	}
	else
	{
		potential.v = potential.circleRadius + vDirection.length();
	}

	std::cout << potential.v << std::endl;
	return true;
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

	// Als zowel de center als het derde punt an de zelfde kant van de boundary ligt, return true
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
	this->boundaryItem->setPen(QPen(QColor(255, 0, 0), 2.0f));
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
