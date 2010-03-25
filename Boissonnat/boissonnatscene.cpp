#include "boissonnatscene.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "triangulationitem.h"
#include "boundaryitem.h"
#include "pointsitem.h"

BoissonnatScene::BoissonnatScene()
	: triangulationItem(NULL), boundaryItem(NULL), pointsItem(NULL)
{
}

BoissonnatScene::~BoissonnatScene()
{
//	this->removeItem(this->triangulationItem);
//	delete this->triangulationItem;
	this->removeItem(this->boundaryItem);
	delete this->boundaryItem;
	this->removeItem(this->pointsItem);
	delete this->pointsItem;
}

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

	/// Skip the first line with the pointcount
	in.readLine();

	while (!in.atEnd()) {
		QStringList elements = in.readLine().split(' ');
		points.append(QPointF(elements[0].toFloat(), elements[1].toFloat()));
    }

	this->triangulationItem = new TriangulationItem(points);
	addItem(this->triangulationItem);

	this->boundaryItem = new BoundaryItem(points);
	addItem(this->boundaryItem);

	this->pointsItem = new PointsItem(points);
	addItem(this->pointsItem);
}

void BoissonnatScene::triangulationStatusChanged(int state)
{
	if (state == 0)
		removeItem(this->triangulationItem);
	else
		addItem(this->triangulationItem);
}

void BoissonnatScene::boundaryStatusChanged(int state)
{
	if (state == 0)
		removeItem(this->boundaryItem);
	else
		addItem(this->boundaryItem);
}

void BoissonnatScene::pointsStatusChanged(int state)
{
	if (state == 0)
		removeItem(this->pointsItem);
	else
		addItem(this->pointsItem);
}
