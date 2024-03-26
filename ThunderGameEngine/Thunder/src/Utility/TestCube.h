#ifndef TESTCUBE_H
#define TESTCUBE_H

#include <vector>
#include <glm/glm.hpp>
#include <gl/glew.h>
#include "../ECS/RenderComponent3D.h"
#include "../ECS/TransformComponent.h"

class TestCube
{
public:
	TestCube();
	~TestCube();

	RenderComponent3D GetRenderComponent() { return *cubeRender; };
	TransformComponent GetTransformComponent() { return cubeTransform; };

private:
	std::vector<glm::vec3> vertices;
	std::vector<GLuint> indices;
	std::vector<glm::vec4> color;

	RenderComponent3D* cubeRender;
	TransformComponent cubeTransform;
};

#endif // !TESTCUBE_H

