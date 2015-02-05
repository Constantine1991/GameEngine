#include "texture.h"
Texture::Texture()
{
    this->initialize();
}

Texture::Texture(QString file)
{
    this->initialize();
    this->load(file);
}

Texture::~Texture()
{
    if(this->id!=0)
        this->clear();
}

bool Texture::load(QString file)
{
    QImage image;
    if(!image.load(file))
        return false;
    image=image.convertToFormat(QImage::Format_RGBA8888);
    image=image.mirrored();
    glGenTextures(1,&this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    glBindTexture(GL_TEXTURE_2D, 0);
    this->widthT=image.width();
    this->heightT=image.height();
    return true;
}

void Texture::clear()
{
    glDeleteTextures(1,&this->id);
    this->id=0;
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, this->id);
}

void Texture::unbind()
{
   glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::idTexture() const
{
    return this->id;
}

int Texture::width() const
{
    return this->widthT;
}

int Texture::height() const
{
    return this->heightT;
}

void Texture::initialize()
{
    this->id=0;
    this->widthT=0;
    this->heightT=0;
}
