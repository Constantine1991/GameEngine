#ifndef TESTGAME_H
#define TESTGAME_H
#include "gamewindow.h"
#include "shader.h"
#include "texture.h"

class TestGame:public GameWindow
{
    Q_OBJECT
public:
    Texture img;
    Shader  shader;
    QMatrix4x4 mat_pos;
    QMatrix4x4 mat_p;
    QMatrix4x4 mat_tex;
    TestGame(QWindow *parent=0);
    virtual void initGameWindow();
    virtual void updateGameWindow();
    virtual void drawGameWindow();
    virtual void destroyGameWindow();
};

#endif // TESTGAME_H
