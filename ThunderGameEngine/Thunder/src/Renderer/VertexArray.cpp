#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &arrayID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &arrayID);
}

void VertexArray::Bind() const {
    glBindVertexArray(arrayID);
    for (const auto& attribute : attributes) {
        attribute.Enable();
    }
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}

void VertexArray::AddAttribute(const VertexAttribute& attribute) {
    Bind();
    attribute.Enable();
    Unbind();
    attributes.push_back(attribute);
}