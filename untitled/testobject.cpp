#include "testobject.h"

TestObject::TestObject()
{
}

int TestObject::type()
{
    return 1;
}

void TestObject::init()
{
    this->img.load("://Resources/buttonexitmenu.png");
    this->shader.load("://Resources/Vertex.vsh","://Resources/Frag.fsh");
    this->shader.createVAO("Vertex","Texture");
    this->setPos(100,100,0);
    this->setScaled(100);
    mat_p.ortho(0,800,0,600,-1,1);
}

void TestObject::update()
{
    this->setPos(Mouse::x,600-Mouse::y,0);
    if(Keyboard::keyRelease(Qt::Key_A))
        this->setRotate(this->rotate()+45);
    if(Keyboard::keyRelease(Qt::Key_1))
        this->setMirror(1,1);
    if(Keyboard::keyRelease(Qt::Key_2))
        this->setMirror(-1,1);
    if(Keyboard::keyRelease(Qt::Key_3))
        this->setMirror(1,-1);
    if(Keyboard::keyRelease(Qt::Key_4))
        this->setMirror(-1,-1);
    if(Mouse::buttonPress(Qt::LeftButton))
        this->setScaled(this->scaled().x()+1);
    if(Mouse::buttonPress(Qt::RightButton))
        this->setScaled(this->scaled().x()-1);
}

void TestObject::draw()
{
    this->shader.bind();
    this->shader.vertexArrayObject()->bind();
    this->img.bind();
    this->shader.setUniformValue("MatrixTex", this->matrix(Transform::MatrixIsTexture));
    this->shader.setUniformValue("MatrixPos",mat_p*this->matrix(Transform::MatrixIsPosition));
    glDrawArrays(GL_TRIANGLES, 0, 6);
    this->shader.vertexArrayObject()->release();
    this->img.unbind();
    this->shader.release();
}

void TestObject::destroy()
{

}
