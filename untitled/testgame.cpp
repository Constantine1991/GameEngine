#include "testgame.h"
#include <QDebug>

TestGame::TestGame(QWindow *parent):GameWindow(parent)
{
    this->object=new TestObject();
}

void TestGame::initGameWindow()
{
    this->setTitle("Игра");
    this->glViewport(0,0,800,600);
    this->object->init();
}

void TestGame::updateGameWindow()
{
    this->object->update();
}

void TestGame::drawGameWindow()
{
    this->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    this->object->draw();
}

void TestGame::destroyGameWindow()
{

}
