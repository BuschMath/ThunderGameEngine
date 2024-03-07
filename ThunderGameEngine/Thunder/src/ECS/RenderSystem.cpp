#include "RenderSystem.h"

RenderSystem::RenderSystem(ComponentManager& componentManager, Shader& shader)
	: m_componentManager(componentManager), m_shader(shader)
{
}

RenderSystem::~RenderSystem()
{
}

ComponentManager& RenderSystem::GetComponentManager() const
{
	return m_componentManager;
}

Shader& RenderSystem::GetShader() const
{
	return m_shader;
}
