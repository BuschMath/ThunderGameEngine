#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "Component.h"
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

struct RenderComponent : public Component {
    std::vector<glm::vec3> vertices;  // 3D vertex positions
    std::vector<glm::vec2> texCoords; // 2D texture coordinates
    std::vector<GLuint> indices;      // Indices for indexed drawing
    GLuint textureID;                  // Texture ID

    RenderComponent(const std::vector<glm::vec3>& verts, const std::vector<GLuint>& inds,
        const std::vector<glm::vec2>& tex, GLuint texID)
        : vertices(verts), indices(inds), texCoords(tex), textureID(texID) {}
};

#endif // RENDERCOMPONENT_H


