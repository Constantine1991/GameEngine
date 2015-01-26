#include "geometry.h"

QPointF Geometry::centerLine(QPointF p1, QPointF p2)
{
    return QPointF((p1.x()+p2.x())/2,(p1.y()+p2.y())/2);
}

QPointF Geometry::centerLine(QLineF line)
{
    return Geometry::centerLine(line.p1(),line.p2());
}

float Geometry::radians(float angle)
{
   return PI*angle/180;
}

float Geometry::angle(float radians)
{
    return PI/180*radians;
}

float Geometry::lengthLine(QPointF p1, QPointF p2)
{
    return ::sqrtf(::powf(p1.x()-p2.x(),2)+::powf(p1.y()-p2.y(),2));
}
