#ifndef TRIANGULATIONITEM_H
#define TRIANGULATIONITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsPolygonItem>
#include <QPointF>

// A triangle item that holds the three points and draws the triangle through the polygon item class
class TriangleItem : public QGraphicsPolygonItem
{
public:
	TriangleItem(QPointF points[]);
	TriangleItem(QPointF point0, QPointF point1, QPointF point2);
	virtual ~TriangleItem();

private:
	QPointF points[3];

};

// Graphics items group that holds all the triangles after the delaunay triangulation is done
class TriangulationItem : public QGraphicsItemGroup
{
public:
	TriangulationItem(const QVector<QPointF>& points);
	virtual ~TriangulationItem();

private:
	QVector<TriangleItem*> triangles;
};

#endif // TRIANGULATIONITEM_H
