#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <GL/glew.h>
#include <vector>
#include "VertexAttribute.h"

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;
    void AddAttribute(const VertexAttribute& attribute);

private:
    GLuint arrayID;
    std::vector<VertexAttribute> attributes;
};

#endif // VERTEXARRAY_H

