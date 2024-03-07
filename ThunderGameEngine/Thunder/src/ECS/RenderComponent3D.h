#ifndef RENDERCOMPONENT3D_H
#define RENDERCOMPONENT3D_H

#include "Component.h"
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

struct RenderComponent3D : public Component {
    std::vector<glm::vec3> vertices;  // 3D vertex positions
    std::vector<GLuint> indices;      // Indices for indexed drawing
    glm::vec4 color;                  // RGBA color

    RenderComponent3D(const std::vector<glm::vec3>& verts, const std::vector<GLuint>& inds, const glm::vec4& col)
        : vertices(verts), indices(inds), color(col) {}
};

#endif // RENDERCOMPONENT2D_H

