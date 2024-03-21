#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "ComponentManager.h"
#include "../Renderer/Shader.h"
#include "RenderComponent3D.h"
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

	void Update()
	{
		glm::mat4 projMatrix, vMatrix;
		// Get all entities with a CameraComponent
		// There should only be one camera entity
		std::vector<Entity> cameraEntities = GetComponentManager().GetAllEntitiesWithComponent<CameraComponent>();
		for (const Entity& entity : cameraEntities) {
			GetComponentManager().GetComponent<CameraComponent>(entity).UpdateProjectionMatrix();
			projMatrix = GetComponentManager().GetComponent<CameraComponent>(entity).GetProjectionMatrix();

			glm::vec3 position = GetComponentManager().GetComponent<TransformComponent>(entity).GetPosition();
			glm::quat orientation = GetComponentManager().GetComponent<TransformComponent>(entity).GetRotation();
			vMatrix = GetComponentManager().GetComponent<CameraComponent>(entity).GetViewMatrix(position, orientation);
		}
		// Get all entities with a RenderComponent3D
		std::vector<Entity> entities = GetComponentManager().GetAllEntitiesWithComponent<RenderComponent3D>();
		for (const Entity& entity : entities) {
			RenderEntity(entity, projMatrix, vMatrix);
		}
	};

	void RenderEntity(const Entity& entity, glm::mat4 projectionMatrix, glm::mat4 viewMatrix);

	ComponentManager& GetComponentManager() const;
	Shader& GetShader() const;

private:
	ComponentManager& m_componentManager;
	Shader& m_shader;
};

#endif // RENDER_SYSTEM_H