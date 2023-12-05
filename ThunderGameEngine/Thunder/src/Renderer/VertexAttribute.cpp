#include "VertexAttribute.h"

VertexAttribute::VertexAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, 
    GLsizei stride, const void* pointer)
    : index(index) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}

void VertexAttribute::Enable() const {
    glEnableVertexAttribArray(index);
}
