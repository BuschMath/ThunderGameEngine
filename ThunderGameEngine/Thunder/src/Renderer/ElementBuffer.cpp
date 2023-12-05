#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(const GLuint* indices, unsigned int count) : count(count) {
    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), indices, GL_STATIC_DRAW);
}

ElementBuffer::~ElementBuffer() {
    glDeleteBuffers(1, &bufferID);
}

void ElementBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void ElementBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int ElementBuffer::GetCount() const {
    return count;
}
