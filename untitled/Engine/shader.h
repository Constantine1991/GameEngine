#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include "mesh.h"

class Shader:public QOpenGLShaderProgram
{
public:
    Shader();
    Shader(QString vertexShader,QString fragmentShader);
    ~Shader();
    bool load(QString vertexShader,QString fragmentShader);
    void createVAO(QString nameVertexMatrix,QString nameTextureMatrix);
    QOpenGLVertexArrayObject *vertexArrayObject();
private:
     QOpenGLVertexArrayObject *vertexAO;
};

#endif // SHADER_H
