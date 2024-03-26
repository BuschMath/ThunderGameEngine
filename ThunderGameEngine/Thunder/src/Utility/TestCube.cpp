#include "TestCube.h"

TestCube::TestCube()
{
	vertices = {
		glm::vec3(-0.5f, -0.5f, 0.5f),	// 0
		glm::vec3(-0.5f, -0.5f, -0.5f),	// 1
		glm::vec3(0.5f, -0.5f, 0.5f),	// 2
		glm::vec3(0.5f, -0.5f, -0.5f),	// 3
		glm::vec3(-0.5f, 0.5f, 0.5f),	// 4
		glm::vec3(-0.5f, 0.5f, -0.5f),	// 5
		glm::vec3(0.5f, 0.5f, 0.5f),	// 6
		glm::vec3(0.5f, 0.5f, -0.5f),	// 7
	};

	indices = {
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

	color = {
		glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),
		glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
		glm::vec4(1.0f, 0.0f, 1.0f, 1.0f),
		glm::vec4(0.0f, 1.0f, 1.0f, 1.0f),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
	};

	cubeRender = new RenderComponent3D(vertices, indices, color);
}

TestCube::~TestCube()
{
}