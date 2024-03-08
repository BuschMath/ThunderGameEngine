
#include "Engine.h"
#include "ECS/RenderComponent3D.h"

int main() {
    
    std::vector<glm::vec3> vertices = {
		glm::vec3(-0.5f, -0.5f, 0.5f),	// 0
		glm::vec3(-0.5f, -0.5f, -0.5f),	// 1
		glm::vec3(0.5f, -0.5f, 0.5f),	// 2
		glm::vec3(0.5f, -0.5f, -0.5f),	// 3
		glm::vec3(-0.5f, 0.5f, 0.0f),	// 4
		glm::vec3(-0.5f, 0.5f, -1.0f),	// 5
		glm::vec3(0.5f, 0.5f, 0.0f),	// 6
		glm::vec3(0.5f, 0.5f, -1.0f),	// 7
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

	glm::vec4 color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

    RenderComponent3D component(vertices, indices, color);

	/*std::vector<glm::vec2> triangleVertices = {
		glm::vec2(-0.5f, -0.5f),
		glm::vec2(0.5f, -0.5f),
		glm::vec2(0.0f, 0.5f)
	};

	std::vector<GLuint> triangleIndices = {
		0, 1, 2
	};

	glm::vec4 triangleColor = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);

	RenderComponent2D triangleComponent(triangleVertices, triangleIndices, triangleColor);
	*/
    Engine engine(800, 600, "Thunder Game Engine");

	Entity entity = engine.CreateEntity();
	//Entity triangleEntity = engine.CreateEntity();

	engine.AddComponent(entity, component);
	//engine.AddComponent(triangleEntity, triangleComponent);

    engine.Run();

    return 0;
}
