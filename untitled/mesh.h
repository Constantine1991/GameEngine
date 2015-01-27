#ifndef MESH_H
#define MESH_H
#include <QOpenGLBuffer>

class Mesh
{
public:
    Mesh();
    ~Mesh();
    static QOpenGLBuffer *vertexMesh();
    static QOpenGLBuffer *textureMesh();
private:
    static QOpenGLBuffer *bufferVertexCoords;
    static QOpenGLBuffer *bufferTextureCoords;
    static float *texture;
    static float *vertex;
};

#endif // MESH_H
