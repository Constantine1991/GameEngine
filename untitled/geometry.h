#ifndef GEOMETRY_H
#define GEOMETRY_H
#define PI  3.14159265358979323846

#include <qmath.h>
#include <QPointF>
#include <QLineF>

class Geometry
{
public:
    ////
    /// \brief centerLine - Возвращает точку центра линии на координатной оси XY
    /// \param p1 - начальная точка линии
    /// \param p2 - конечнаа точка линии
    /// \return Возвращает точку центра линии на координатной оси XY
    ///
    static QPointF centerLine(QPointF p1,QPointF p2);
    static QPointF centerLine(QLineF line);
    ///
    /// \brief radians - Переводит градусы в радианы
    /// \param angle - градусы
    /// \return - Возвращает радианы
    ///
    static float radians(float angle);
    ///
    /// \brief angle - Переводит радианы в градусы
    /// \param radians  - радианы
    /// \return - Возвращает градусы
    ///
    static float angle(float radians);
    ///
    /// \brief lengthLine - Длинна линии
    /// \param p1 - точка
    /// \param p2 - точка
    /// \return - Возвращает длинну линии от точки до точки
    ///
    static float lengthLine(QPointF p1,QPointF p2);
};

#endif // GEOMETRY_H
