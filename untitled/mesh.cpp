#include "mesh.h"
QOpenGLBuffer *Mesh::bufferTextureCoords=NULL;
QOpenGLBuffer *Mesh::bufferVertexCoords=NULL;
float *Mesh::texture=NULL;
float *Mesh::vertex=NULL;

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
    this->bufferTextureCoords->destroy();
    this->bufferVertexCoords->destroy();
    delete[]Mesh::vertex;
    delete[]Mesh::texture;
}

QOpenGLBuffer *Mesh::textureMesh()
{
    if(Mesh::bufferTextureCoords==NULL)
    {
        Mesh::bufferTextureCoords=new QOpenGLBuffer();
        Mesh::texture=new float [12];
        Mesh::texture[0]=Mesh::texture[2]=Mesh::texture[3]=Mesh::texture[5]=Mesh::texture[6]=Mesh::texture[11]=0.0f;
        Mesh::texture[1]=Mesh::texture[4]=Mesh::texture[7]=Mesh::texture[8]=Mesh::texture[9]=Mesh::texture[10]=1.0f;
        Mesh::bufferTextureCoords->create();
        Mesh::bufferTextureCoords->bind();
        Mesh::bufferTextureCoords->allocate(Mesh::texture,sizeof(float)*12);
        Mesh::bufferTextureCoords->release();
    }
    return Mesh::bufferTextureCoords;
}

QOpenGLBuffer *Mesh::vertexMesh()
{
    if(Mesh::bufferVertexCoords==NULL)
    {
        Mesh::bufferVertexCoords=new QOpenGLBuffer();
        Mesh::vertex=new float[18];
        Mesh::vertex[0]=Mesh::vertex[2]=Mesh::vertex[3]=Mesh::vertex[4]=Mesh::vertex[5]=Mesh::vertex[7]=Mesh::vertex[8]=
        Mesh::vertex[9]=Mesh::vertex[11]=Mesh::vertex[14]=Mesh::vertex[16]=Mesh::vertex[17]=0.0f;
        Mesh::vertex[1]=Mesh::vertex[6]=Mesh::vertex[10]=Mesh::vertex[12]=Mesh::vertex[13]=Mesh::vertex[15]=1.0f;
        Mesh::bufferVertexCoords->create();
        Mesh::bufferVertexCoords->bind();
        Mesh::bufferVertexCoords->allocate(Mesh::vertex,sizeof(float)*18);
        Mesh::bufferVertexCoords->release();
    }
    return Mesh::bufferVertexCoords;
}
