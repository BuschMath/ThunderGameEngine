#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "ComponentManager.h"
#include "../Renderer/Shader.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "CameraComponent.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/VertexBuffer.h"
#include "../Renderer/VertexAttribute.h"
#include "../Renderer/ElementBuffer.h"
#include <glm/gtc/quaternion.hpp>
#include <vector>

class RenderSystem
{
public:
	RenderSystem(ComponentManager& componentManager, Shader& shader);
	~RenderSystem();

	void Update();

	void RenderEntity(const Entity& entity, glm::mat4 projectionMatrix, glm::mat4 viewMatrix);

	ComponentManager& GetComponentManager() const;
	Shader& GetShader() const;

private:
	ComponentManager& m_componentManager;
	Shader& m_shader;
};

#endif // RENDER_SYSTEM_H