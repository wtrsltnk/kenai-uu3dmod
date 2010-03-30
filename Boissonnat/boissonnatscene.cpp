#include "boissonnatscene.h"
#include "triangulationitem.h"
#include "boundaryitem.h"
#include "pointsitem.h"
#include <iostream>

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
	std::cout << "Step!" << std::endl;
	return false;
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
