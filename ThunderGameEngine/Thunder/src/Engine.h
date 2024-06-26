#ifndef ENGINE_H
#define ENGINE_H

#include "ECS/EntityManager.h"
#include "ECS/ComponentManager.h"
#include "Renderer/Renderer.h"
#include "Renderer/Window.h"
#include "Utility/TextureLoader.h"
#include "Utility/Cube.h"
#include "Utility/TestCube.h"

class Engine
{
public:
	Engine(int winHeight, int winWidth, const char* winTitle);
	~Engine();

	Entity CreateEntity();

	template<typename T>
	void AddComponent(Entity entity, T componentType)
	{
		p_componentManager->AddComponent(entity, componentType);
	};

	Entity CreateCamera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up,
		float fov, float aspectRatio, float nearClip, float farClip);

	Entity CreateTestCube();
	Entity CreateCube(const char* texturePath);

	void Run();

private:
	int m_winHeight;
	int m_winWidth;
	std::string m_winTitle;
	Window* p_window;
	Renderer* p_renderer;
	EntityManager* p_entityManager;
	ComponentManager* p_componentManager;
};

#endif // !ENGINE_H
