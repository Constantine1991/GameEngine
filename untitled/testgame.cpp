#include "testgame.h"
#include <QDebug>

TestGame::TestGame(QWindow *parent):GameWindow(parent)
{
}

void TestGame::initGameWindow()
{
    this->setTitle("Игра");
    this->glViewport(0,0,800,600);
    Mesh::mesh()->create();
    this->img.load("://Resources/buttonexitmenu.png");
    this->shader.load("://Resources/Vertex.vsh","://Resources/Frag.fsh");
    this->shader.createVAO("Vertex","Texture");
    mat_tex.setToIdentity();
    mat_pos.setToIdentity();
    mat_p.setToIdentity();
    mat_pos.translate(400,400,0);
    mat_pos.scale(100,100);
    mat_p.ortho(0,800,0,600,-1,1);
}

void TestGame::updateGameWindow()
{
    mat_pos.setToIdentity();
    mat_pos.translate(Mouse::x,600-Mouse::y,0);
    mat_pos.scale(100,100);
    if(Keyboard::keyRelease(Qt::Key_A))
        qDebug()<<"Key Release A";
    if(Mouse::buttonRelease(Qt::LeftButton))
        qDebug()<<"Mouse button release left";
}

void TestGame::drawGameWindow()
{
    this->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    this->shader.bind();
    this->img.bind();
    this->shader.vertexArrayObject()->bind();
    this->shader.setUniformValue("MatrixTex", mat_tex);
    this->shader.setUniformValue("MatrixPos",mat_p*mat_pos);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    this->shader.vertexArrayObject()->release();
    this->img.unbind();
    this->shader.release();
}

void TestGame::destroyGameWindow()
{

}
