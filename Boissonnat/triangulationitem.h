#ifndef TRIANGULATIONITEM_H
#define TRIANGULATIONITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsPolygonItem>
#include <QPointF>

// A triangle item that holds the three points and draws the triangle through the polygon item class
class TriangleItem : public QGraphicsItemGroup
{
public:
	TriangleItem(QPointF points[]);
	TriangleItem(QPointF point0, QPointF point1, QPointF point2);
	virtual ~TriangleItem();

	QPointF points[3];
	QPointF circleCenter;
	float radius;

protected:
	void setupItem();
	void calculateCircleCenter();

private:
	QGraphicsPolygonItem* polygonItem;
	QGraphicsEllipseItem* circleItem;

};

// Graphics items group that holds all the triangles after the delaunay triangulation is done
class TriangulationItem : public QGraphicsItemGroup
{
public:
	TriangulationItem(const QVector<QPointF>& points);
	virtual ~TriangulationItem();

	void removeTriangle(TriangleItem* item);

private:
	QVector<TriangleItem*> triangles;
};

#endif // TRIANGULATIONITEM_H
