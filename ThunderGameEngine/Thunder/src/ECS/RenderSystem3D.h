#ifndef RENDERSYSTEM3D_H
#define RENDERSYSTEM3D_H

#include "RenderComponent3D.h"
#include "RenderSystem.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/VertexBuffer.h"
#include "../Renderer/VertexAttribute.h"
#include "../Renderer/ElementBuffer.h"
#include <vector>

class RenderSystem3D : public RenderSystem {
public:
    RenderSystem3D(ComponentManager& componentManager, Shader& shader);

    void Update() override; // Call this function every frame

private:
    void RenderEntity(const Entity& entity); // Helper function for rendering a single entity
};

#endif // RENDERSYSTEM3D_H


