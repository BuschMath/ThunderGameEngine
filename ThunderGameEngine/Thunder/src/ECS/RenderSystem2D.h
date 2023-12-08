#ifndef RENDERSYSTEM2D_H
#define RENDERSYSTEM2D_H

#include "ComponentManager.h"
#include "RenderComponent2D.h"
#include "../Renderer/Shader.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/VertexBuffer.h"
#include "../Renderer/VertexAttribute.h"
#include "../Renderer/ElementBuffer.h"
#include <vector>

class RenderSystem2D {
public:
    RenderSystem2D(ComponentManager& componentManager, const Shader& shader)
        : componentManager(componentManager), shader(shader) {}

    void Update(); // Call this function every frame

private:
    ComponentManager& componentManager;
    const Shader& shader; // Assume a basic shader for 2D rendering

    void RenderEntity(const Entity& entity); // Helper function for rendering a single entity
};

#endif // RENDERSYSTEM2D_H

