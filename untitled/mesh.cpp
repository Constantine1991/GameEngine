#include "mesh.h"
Mesh *Mesh::m=NULL;
/*QOpenGLBuffer *Mesh::bufferTextureCoords=NULL;
QOpenGLBuffer *Mesh::bufferVertexCoords=NULL;
float *Mesh::texture=NULL;
float *Mesh::vertex=NULL;*/

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
    this->bufferTextureCoords->destroy();
    this->bufferVertexCoords->destroy();
    delete[]this->vertex;
    delete[]this->texture;
}

void Mesh::create()
{
    this->bufferTextureCoords=new QOpenGLBuffer();
    this->texture=new float [12];
    this->texture[0]=this->texture[2]=this->texture[3]=this->texture[5]=this->texture[6]=this->texture[11]=0.0f;
    this->texture[1]=this->texture[4]=this->texture[7]=this->texture[8]=this->texture[9]=this->texture[10]=1.0f;
    this->bufferTextureCoords->create();
    this->bufferTextureCoords->bind();
    this->bufferTextureCoords->allocate(texture,sizeof(float)*12);
    this->bufferTextureCoords->release();
    this->bufferVertexCoords=new QOpenGLBuffer();
    this->vertex=new float[18];
    this->vertex[0]=this->vertex[2]=this->vertex[3]=this->vertex[4]=this->vertex[5]=this->vertex[7]=this->vertex[8]=
    this->vertex[9]=this->vertex[11]=this->vertex[14]=this->vertex[16]=this->vertex[17]=0.0f;
    this->vertex[1]=this->vertex[6]=this->vertex[10]=this->vertex[12]=this->vertex[13]=this->vertex[15]=1.0f;
    this->bufferVertexCoords->create();
    this->bufferVertexCoords->bind();
    this->bufferVertexCoords->allocate(vertex,sizeof(float)*18);
    this->bufferVertexCoords->release();
}

Mesh *Mesh::mesh()
{
    if(Mesh::m==NULL)
    {
        Mesh::m=new Mesh();
    }
    return Mesh::m;
}

QOpenGLBuffer *Mesh::textureMesh()
{
    /*if(Mesh::bufferTextureCoords==NULL)
    {
        Mesh::bufferTextureCoords=new QOpenGLBuffer();
        Mesh::texture=new float [12];
        Mesh::texture[0]=Mesh::texture[2]=Mesh::texture[3]=Mesh::texture[5]=Mesh::texture[6]=Mesh::texture[11]=0.0f;
        Mesh::texture[1]=Mesh::texture[4]=Mesh::texture[7]=Mesh::texture[8]=Mesh::texture[9]=Mesh::texture[10]=1.0f;
        Mesh::bufferTextureCoords->create();
        Mesh::bufferTextureCoords->bind();
        Mesh::bufferTextureCoords->allocate(texture,sizeof(float)*12);
        Mesh::bufferTextureCoords->release();
    }*/
    return this->bufferTextureCoords;
}

QOpenGLBuffer *Mesh::vertexMesh()
{
    /*if(Mesh::bufferVertexCoords==NULL)
    {
        Mesh::bufferVertexCoords=new QOpenGLBuffer();
        Mesh::vertex=new float[18];
        Mesh::vertex[0]=Mesh::vertex[2]=Mesh::vertex[3]=Mesh::vertex[4]=Mesh::vertex[5]=Mesh::vertex[7]=Mesh::vertex[8]=
        Mesh::vertex[9]=Mesh::vertex[11]=Mesh::vertex[14]=Mesh::vertex[16]=Mesh::vertex[17]=0.0f;
        Mesh::vertex[1]=Mesh::vertex[6]=Mesh::vertex[10]=Mesh::vertex[12]=Mesh::vertex[13]=Mesh::vertex[15]=1.0f;
        Mesh::bufferVertexCoords->create();
        Mesh::bufferVertexCoords->bind();
        Mesh::bufferVertexCoords->allocate(vertex,sizeof(float)*18);
        Mesh::bufferVertexCoords->release();
    }*/
    return this->bufferVertexCoords;
}
