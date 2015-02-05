#ifndef TESTGAME_H
#define TESTGAME_H
#include "Engine/gamewindow.h"
#include "testobject.h"

class TestGame:public GameWindow
{
    Q_OBJECT
public:
    TestObject *object;
    GameObject *a;
    TestGame(QWindow *parent=0);
    virtual void initGameWindow();
    virtual void updateGameWindow();
    virtual void drawGameWindow();
    virtual void destroyGameWindow();
};

#endif // TESTGAME_H
