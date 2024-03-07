#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "ComponentManager.h"
#include "../Renderer/Shader.h"

class RenderSystem
{
public:
	RenderSystem(ComponentManager& componentManager, Shader& shader);
	~RenderSystem();

	virtual void Update() {};

	ComponentManager& GetComponentManager() const;
	Shader& GetShader() const;

private:
	ComponentManager& m_componentManager;
	Shader& m_shader;
};

#endif // RENDER_SYSTEM_H