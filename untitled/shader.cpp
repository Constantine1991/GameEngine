#include "shader.h"

Shader::Shader()
{
    this->vertexAO=new QOpenGLVertexArrayObject;
}

Shader::Shader(QString vertexShader, QString fragmentShader)
{
    this->load(vertexShader,fragmentShader);
}

Shader::~Shader()
{
    this->removeAllShaders();
    this->vertexAO->destroy();
}

bool Shader::load(QString vertexShader, QString fragmentShader)
{
    this->create();
    if(!this->addShaderFromSourceFile(QOpenGLShader::Vertex,vertexShader))
        return false;
    if(!this->addShaderFromSourceFile(QOpenGLShader::Fragment,fragmentShader))
        return false;
    if(!this->link())
        return false;
    return true;
}

void Shader::createVAO(QString nameVertexMatrix, QString nameTextureMatrix)
{
    vertexAO->create();
    vertexAO->bind();
    Mesh::vertexMesh()->bind();
    this->enableAttributeArray(nameVertexMatrix.toStdString().c_str());
    this->setAttributeBuffer(nameVertexMatrix.toStdString().c_str(),GL_FLOAT,0,3);
    Mesh::textureMesh()->bind();
    this->enableAttributeArray(nameTextureMatrix.toStdString().c_str());
    this->setAttributeBuffer(nameTextureMatrix.toStdString().c_str(),GL_FLOAT,0,2);
    vertexAO->release();
}

QOpenGLVertexArrayObject *Shader::vertexArrayObject()
{
    return this->vertexAO;
}
