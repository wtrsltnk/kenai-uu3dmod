#include "boissonnatscene.h"
#include "triangulationitem.h"
#include "boundaryitem.h"
#include "pointsitem.h"

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
		QPointF point(elements[0].toFloat(), elements[1].toFloat());
		if (points.contains(point) == false)
			points.append(point	);
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
