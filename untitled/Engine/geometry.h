#ifndef GEOMETRY_H
#define GEOMETRY_H
#define PI  3.14159265358979323846

#include <qmath.h>
#include <QPointF>
#include <QLineF>

class Geometry
{
public:
    static QPointF centerLine(QPointF p1,QPointF p2);
    static QPointF centerLine(QLineF line);
    static float radians(float angle);
    static float angle(float radians);
    static float lengthLine(QPointF p1,QPointF p2);
    static float lengthLine(QLineF line);
};

#endif // GEOMETRY_H
