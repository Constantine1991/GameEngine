#ifndef MESH_H
#define MESH_H
#include <QOpenGLBuffer>
#include <QDebug>

class Mesh
{
public:
    Mesh();
    ~Mesh();
    void create();
    static Mesh *mesh();
    QOpenGLBuffer *vertexMesh();
    QOpenGLBuffer *textureMesh();
private:
    static Mesh *m;
    QOpenGLBuffer *bufferVertexCoords;
    QOpenGLBuffer *bufferTextureCoords;
    float *texture;
    float *vertex;
};

#endif // MESH_H
