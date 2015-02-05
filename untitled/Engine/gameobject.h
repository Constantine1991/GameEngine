#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "transform.h"

class GameObject:public Transform
{
public:
    GameObject();
    virtual void update()=0;
    virtual void draw()=0;
    virtual int type()=0;
};

#endif // GAMEOBJECT_H
