#include "triangulationitem.h"
#include "geompack.h"
#include <QPen>
#include <QVector2D>
#include <iostream>

TriangleItem::TriangleItem(QPointF points[])
{
	QPolygonF poly;
	for (int i = 0; i < 3; i++)
	{
		poly << points[i];
		this->points[i] = points[i];
	}
	this->calculateCircleCenter();
	this->polygonItem = new QGraphicsPolygonItem(poly);
	this->polygonItem->setPen(QPen(QColor(200, 155, 0)));
	this->addToGroup(this->polygonItem);

	this->setupItem();
}

TriangleItem::TriangleItem(QPointF point0, QPointF point1, QPointF point2)
{
	this->points[0] = point0;
	this->points[1] = point1;
	this->points[2] = point2;

	QPolygonF poly;
	for (int i = 0; i < 3; i++)
		poly << this->points[i];

	this->calculateCircleCenter();
	this->polygonItem = new QGraphicsPolygonItem(poly);
	this->polygonItem->setPen(QPen(QColor(200, 155, 0)));
	this->addToGroup(this->polygonItem);

	this->setupItem();
}

TriangleItem::~TriangleItem()
{
}

void TriangleItem::setPen(const QPen& pen)
{
	this->polygonItem->setPen(pen);
}

void TriangleItem::setBrush(const QBrush& brush)
{
	this->polygonItem->setBrush(brush);
}

void TriangleItem::setupItem()
{
	QVector2D tmp(this->circleCenter.x() - points[0].x(), this->circleCenter.y() - points[0].y());
	this->radius = tmp.length();
	this->circleItem = new QGraphicsEllipseItem(this->circleCenter.x() - this->radius, this->circleCenter.y() - this->radius, this->radius * 2, this->radius * 2);
//	this->addToGroup(this->circleItem);
}

void TriangleItem::calculateCircleCenter()
{
	double in[6] = { this->points[0].x(), this->points[0].y(),
					 this->points[1].x(), this->points[1].y(),
					 this->points[2].x(), this->points[2].y()
					};

	double* out = triangle_circumcenter_2d(in);
	// Een of andere rare fix voor een vertical flipped y-as
	this->circleCenter = QPointF(out[0], this->points[0].y() + (this->points[0].y() - out[1]));
	delete []out;
}

// With the points to triangulate, create a delaunay triangulation with
// the GEOMPACK method dtris2(). If there was an error, return and don't
// show anything
TriangulationItem::TriangulationItem(const QVector<QPointF>& points)
{
	int error;
	double* g_xy;
	g_xy = new double[2*points.size()];
	int* nod_tri = new int[2*points.size()*3];
	int* triangle_neighbor = new int[2*points.size()*3];
	int tri_num;

	for (int i = 0; i < points.size(); i++)
	{
		g_xy[i * 2] = points[i].x();
		g_xy[i * 2 + 1] = points[i].y();
	}

	error = dtris2 ( points.size(), g_xy, &tri_num, nod_tri, triangle_neighbor );

	if (error != 0)
	{
		// Error handling here
		return;
	}

	int* tmp = nod_tri;
	for (int t = 0; t < tri_num; t++)
	{
		TriangleItem* item = new TriangleItem(points[tmp[0] - 1], points[tmp[1] - 1], points[tmp[2] - 1]);
		this->addToGroup(item);
		this->triangles.append(item);
		tmp += 3;
	}
}

TriangulationItem::~TriangulationItem()
{
}

TriangleItem* TriangulationItem::getTriangle(int index)
{
	if (index >= 0 && index < this->triangles.size())
		return this->triangles.at(index);

	return NULL;
}

void TriangulationItem::removeTriangle(TriangleItem* item)
{
	int index = this->triangles.indexOf(item);
	if (index != -1)
	{
		this->triangles.remove(index);
	}
	item->setPen(QPen(QColor(180, 180, 180)));
	item->setBrush(QBrush(QColor(200, 200, 200)));
}
