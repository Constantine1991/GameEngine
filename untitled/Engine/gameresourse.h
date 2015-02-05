#ifndef GAMERESOURSE_H
#define GAMERESOURSE_H
#include "texture.h"
#include <QGraphicsItem>
#include <QHash>
class GameResourse
{
public:
    GameResourse();
    ~GameResourse();
    bool loadTexture(unsigned int type,QString nameTextureFile);
    void addTexture(unsigned int type,Texture *texture);

private:
    QHash<unsigned int,Texture*> resourse;
};

#endif // GAMERESOURSE_H
