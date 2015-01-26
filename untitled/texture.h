#ifndef TEXTURE_H
#define TEXTURE_H

#include <QOpenGLFunctions>
#include <QImage>

class Texture
{
public:
    Texture();
    Texture(QString file);
    ~Texture();
    bool load(QString file);
    void clear();
    void bind();
    void unbind();
    int width()const;
    int height()const;
    unsigned int idTexture() const;
private:
    int widthT;
    int heightT;
    unsigned int id;
    void initialize();
};

#endif // TEXTURE_H
