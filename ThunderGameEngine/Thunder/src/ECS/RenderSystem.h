#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "ComponentManager.h"
#include "../Renderer/Shader.h"
#include "RenderComponent3D.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/VertexBuffer.h"
#include "../Renderer/VertexAttribute.h"
#include "../Renderer/ElementBuffer.h"
#include <vector>

class RenderSystem
{
public:
	RenderSystem(ComponentManager& componentManager, Shader& shader);
	~RenderSystem();

	void Update()
	{
		std::vector<Entity> entities = GetComponentManager().GetAllEntitiesWithComponent<RenderComponent3D>();
		for (const Entity& entity : entities) {
			RenderEntity(entity);
		}
	};

	void RenderEntity(const Entity& entity);

	ComponentManager& GetComponentManager() const;
	Shader& GetShader() const;

private:
	ComponentManager& m_componentManager;
	Shader& m_shader;
};

#endif // RENDER_SYSTEM_H