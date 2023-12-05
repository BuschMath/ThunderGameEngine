#ifndef RENDERCOMPONENT2D_H
#define RENDERCOMPONENT2D_H

#include "Component.h"
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

struct RenderComponent2D : public Component {
    std::vector<glm::vec2> vertices;  // 2D vertex positions
    std::vector<GLuint> indices;      // Indices for indexed drawing
    glm::vec4 color;                  // RGBA color

    RenderComponent2D(const std::vector<glm::vec2>& verts, const std::vector<GLuint>& inds, const glm::vec4& col)
        : vertices(verts), indices(inds), color(col) {}
};

#endif // RENDERCOMPONENT2D_H
