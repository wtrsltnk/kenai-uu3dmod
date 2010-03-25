#include "boissonnatscene.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "boundaryitem.h"

BoissonnatScene::BoissonnatScene()
	: boundary(NULL)
{
}

BoissonnatScene::~BoissonnatScene()
{
	this->removeItem(this->boundary);
	delete this->boundary;
}

void BoissonnatScene::loadPointFile(QTextStream& in)
{
	if (this->boundary != NULL)
		delete this->boundary;

    this->clear();
    points.clear();

	/// Skip the first line with the pointcount
	in.readLine();

	while (!in.atEnd()) {
		QStringList elements = in.readLine().split(' ');
		QPointF point(elements[0].toFloat(), elements[1].toFloat());
		points.append(point);
		this->addEllipse(point.x()-1, point.y()-1, 2, 2, QPen(QColor(255, 0, 0)), QBrush(QColor(0, 250, 0)));
    }

	this->boundary = new BoundaryItem(points);
	addItem(this->boundary);
}
