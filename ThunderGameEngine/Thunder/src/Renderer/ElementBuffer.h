#ifndef ELEMENTBUFFER_H
#define ELEMENTBUFFER_H

#include <GL/glew.h>

class ElementBuffer {
public:
    ElementBuffer(const GLuint* indices, unsigned int count);
    ~ElementBuffer();

    void Bind() const;
    void Unbind() const;

    unsigned int GetCount() const;

private:
    GLuint bufferID;
    unsigned int count;
};

#endif // ELEMENTBUFFER_H

