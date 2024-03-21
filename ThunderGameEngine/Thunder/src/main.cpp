
#include "Engine.h"
#include "ECS/RenderComponent3D.h"
#include "ECS/CameraComponent.h"
#include "ECS/TransformComponent.h"

int main() {
    
    std::vector<glm::vec3> vertices = {
		glm::vec3(-0.5f, -0.5f, 0.5f),	// 0
		glm::vec3(-0.5f, -0.5f, -0.5f),	// 1
		glm::vec3(0.5f, -0.5f, 0.5f),	// 2
		glm::vec3(0.5f, -0.5f, -0.5f),	// 3
		glm::vec3(-0.5f, 0.5f, 0.5f),	// 4
		glm::vec3(-0.5f, 0.5f, -0.5f),	// 5
		glm::vec3(0.5f, 0.5f, 0.5f),	// 6
		glm::vec3(0.5f, 0.5f, -0.5f),	// 7
	};

    std::vector<GLuint> indices = {
		0, 1, 2,
		2, 3, 1,
		4, 5, 6,
		6, 7, 5,
		0, 1, 4,
		4, 5, 1,
		2, 3, 6,
		6, 7, 3,
		0, 2, 4,
		4, 6, 2,
		1, 3, 5,
		5, 7, 3
	};

	std::vector<glm::vec4> color = {
		glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),
		glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
		glm::vec4(1.0f, 0.0f, 1.0f, 1.0f),
		glm::vec4(0.0f, 1.0f, 1.0f, 1.0f),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
	};

    RenderComponent3D objectRender(vertices, indices, color);
	TransformComponent objectTransform;

    Engine engine(1600, 1200, "Thunder Game Engine");

	Entity object = engine.CreateEntity();
	engine.AddComponent(object, objectRender);
	engine.AddComponent(object, objectTransform);

	Entity camera = engine.CreateCamera(glm::vec3(1, 1, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), 
		60.0f, 1600.0f / 1200.0f, 0.1f, 100.0f);

    engine.Run();

    return 0;
}
