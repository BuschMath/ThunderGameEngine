#ifndef VERTEXATTRIBUTE_H
#define VERTEXATTRIBUTE_H

#include <GL/glew.h>

class VertexAttribute {
public:
    VertexAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, 
        GLsizei stride, const void* pointer);

    void Enable() const;

private:
    GLuint index;
};

#endif // VERTEXATTRIBUTE_H

