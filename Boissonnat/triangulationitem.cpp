#include "triangulationitem.h"
#include "geompack.h"
#include <QPen>

TriangleItem::TriangleItem(QPointF points[])
{
	QPolygonF poly;
	for (int i = 0; i < 3; i++)
	{
		poly << points[i];
		this->points[i] = points[i];
	}
	this->setPolygon(poly);
}

TriangleItem::TriangleItem(QPointF point0, QPointF point1, QPointF point2)
{
	this->points[0] = point0;
	this->points[1] = point1;
	this->points[2] = point2;

	QPolygonF poly;
	for (int i = 0; i < 3; i++)
		poly << this->points[i];

	this->setPolygon(poly);
}

TriangleItem::~TriangleItem()
{
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
		item->setPen(QPen(QColor(200, 155, 0)));
		this->addToGroup(item);
		this->triangles.append(item);
		tmp += 3;
	}
}

TriangulationItem::~TriangulationItem()
{
}
