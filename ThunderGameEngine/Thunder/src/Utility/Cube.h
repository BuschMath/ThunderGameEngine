#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <glm/glm.hpp>
#include <gl/glew.h>
#include "../ECS/RenderComponent.h"
#include "../ECS/TransformComponent.h"

class Cube
{
public:
	Cube(GLuint texID);
	~Cube();

	RenderComponent GetRenderComponent() { return *cubeRender; };
	TransformComponent GetTransformComponent() { return cubeTransform; };

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<GLuint> indices;

	RenderComponent* cubeRender;
	TransformComponent cubeTransform;
};

#endif // !CUBE_H

