#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <QMatrix4x4>
#include <QVector3D>
#include <QVector2D>
#include <QPointF>

class Transform
{
public:
    enum MATRIX{
        MatrixIsTexture     =   1,
        MatrixIsPosition    =   2
    };
    Transform();
    void setPos(float x,float y,float z);
    void setPos(QVector3D posPoint);
    QVector3D pos()const;
    void setRotate(float angle);
    float rotate()const;
    void setScaled(float scale);
    void setScaled(float x,float y);
    QPointF scaled()const;
    void setMirror(int x,int y);
    QVector2D isMirror()const;
    QMatrix4x4 matrix(MATRIX type)const;
private:
    QMatrix4x4 matrixTexture()const;
    QMatrix4x4 matrixPosition()const;
    QVector3D position;
    float angle;
    QPointF scale;
    QVector2D mirror;
};

#endif // TRANSFORM_H
