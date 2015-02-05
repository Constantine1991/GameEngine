#include "transform.h"

Transform::Transform()
{
    this->setPos(0,0,0);
    this->setRotate(0);
    this->setScaled(1);
    this->setMirror(1,1);
}

void Transform::setPos(float x, float y, float z)
{
    this->setPos(QVector3D(x,y,z));
}

void Transform::setPos(QVector3D posPoint)
{
    this->position=posPoint;
}

QVector3D Transform::pos()const
{
    return this->position;
}

void Transform::setRotate(float angle)
{
    angle=angle>360?angle-360:angle;
    this->angle=angle;
}

float Transform::rotate()const
{
    return this->angle;
}

void Transform::setScaled(float scale)
{
    this->setScaled(scale,scale);
}

void Transform::setScaled(float x,float y)
{
    this->scale.setX(x);
    this->scale.setY(y);
}

QPointF Transform::scaled() const
{
    return this->scale;
}

void Transform::setMirror(int x, int y)
{
    this->mirror.setX(x>=0?1:-1);
    this->mirror.setY(y>=0?1:-1);
}

QVector2D Transform::isMirror()const
{
    return this->mirror;
}

QMatrix4x4 Transform::matrix(MATRIX type) const
{
    return type==Transform::MatrixIsPosition?this->matrixPosition():this->matrixTexture();
}

QMatrix4x4 Transform::matrixTexture()const
{
    QMatrix4x4 m;
    m.setToIdentity();
    m.scale(this->mirror.x(),this->mirror.y());
    return m;
}

QMatrix4x4 Transform::matrixPosition()const
{
    QMatrix4x4 mat_pos;
    mat_pos.setToIdentity();
    mat_pos.translate(this->position);

    QMatrix4x4 mat_rot;
    mat_rot.setToIdentity();
    mat_rot.rotate(this->angle, 0, 0, 1);

    QMatrix4x4 mat_scal;
    mat_scal.setToIdentity();
    mat_scal.scale(this->scale.x(),this->scale.y(),1);

    return mat_pos*mat_rot*mat_scal;
}
