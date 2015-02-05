#ifndef TESTOBJECT_H
#define TESTOBJECT_H
#include "Engine/gameobject.h"
#include "Engine/texture.h"
#include "Engine/shader.h"
#include "Engine/mouse.h"
#include "Engine/keyboard.h"

class TestObject:public GameObject
{
public:
    TestObject();
    void init();
    virtual void update();
    virtual void draw();
    void destroy();
    virtual int type();
private:
    Texture img;
    Shader  shader;
    QMatrix4x4 mat_pos;
    QMatrix4x4 mat_p;
    QMatrix4x4 mat_tex;
};

#endif // TESTOBJECT_H
