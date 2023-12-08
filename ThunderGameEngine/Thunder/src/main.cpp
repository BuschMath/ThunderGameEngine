
#include "Engine.h"
#include "ECS/RenderComponent2D.h"

int main() {
    
    std::vector<glm::vec2> vertices = {
		glm::vec2(-0.5f, -0.5f),
		glm::vec2(0.5f, -0.5f),
		glm::vec2(0.5f, 0.5f),
		glm::vec2(-0.5f, 0.5f)
	};

    std::vector<GLuint> indices = {
		0, 1, 2,
		2, 3, 0
	};

	glm::vec4 color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

    RenderComponent2D component(vertices, indices, color);

	std::vector<glm::vec2> triangleVertices = {
		glm::vec2(-0.5f, -0.5f),
		glm::vec2(0.5f, -0.5f),
		glm::vec2(0.0f, 0.5f)
	};

	std::vector<GLuint> triangleIndices = {
		0, 1, 2
	};

	glm::vec4 triangleColor = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);

	RenderComponent2D triangleComponent(triangleVertices, triangleIndices, triangleColor);

    Engine engine(800, 600, "Thunder Game Engine");

	Entity entity = engine.CreateEntity();
	Entity triangleEntity = engine.CreateEntity();

	engine.AddComponent(entity, component);
	engine.AddComponent(triangleEntity, triangleComponent);

    engine.Run();

    return 0;
}
