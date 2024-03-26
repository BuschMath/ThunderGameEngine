#include "Cube.h"

Cube::Cube(GLuint texID)
{
	vertices = {
		glm::vec3{-0.5f, -0.5f, -0.5f},
		glm::vec3{ 0.5f, -0.5f, -0.5f},  
		glm::vec3{ 0.5f,  0.5f, -0.5f},  
		glm::vec3{-0.5f,  0.5f, -0.5f},  
		glm::vec3{-0.5f, -0.5f,  0.5f},  
		glm::vec3{ 0.5f, -0.5f,  0.5f},  
		glm::vec3{ 0.5f,  0.5f,  0.5f},  
		glm::vec3{-0.5f,  0.5f,  0.5f}  
	};

	texCoords = {
		glm::vec2{0.0f, 0.0f},
		glm::vec2{1.0f, 0.0f},
		glm::vec2{1.0f, 1.0f},
		glm::vec2{0.0f, 1.0f},
		glm::vec2{0.0f, 0.0f},
		glm::vec2{1.0f, 0.0f},
		glm::vec2{1.0f, 1.0f},
		glm::vec2{0.0f, 1.0f}
	};

	indices = {
		0, 1, 2,  2, 3, 0,
		1, 5, 6,  6, 2, 1,
		7, 6, 5,  5, 4, 7,
		4, 0, 3,  3, 7, 4,
		4, 5, 1,  1, 0, 4,
		3, 2, 6,  6, 7, 3
	};

	cubeRender = new RenderComponent(vertices, indices, texCoords, texID);
}

Cube::~Cube()
{
}