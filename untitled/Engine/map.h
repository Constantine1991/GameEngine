#ifndef MAP_H
#define MAP_H
#include <QFile>
#include "texture.h"
#include "shader.h"
#include "gameobject.h"

class Map
{
public:
    Map();
    ~Map();
    bool load(QString nameMap);
    void clear();
    void draw();

};

#endif // MAP_H
