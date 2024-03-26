#include "Cube.h"

Cube::Cube(GLuint texID)
{
	vertices = {
		glm::vec3{-1.0f, -1.0f, -1.0f},
		glm::vec3{ 1.0f, -1.0f, -1.0f},
		glm::vec3{ 1.0f, -1.0f,  1.0f},
		glm::vec3{-1.0f, -1.0f,  1.0f},
		
		glm::vec3{-1.0f,  1.0f, -1.0f},
		glm::vec3{ 1.0f,  1.0f, -1.0f},
		glm::vec3{ 1.0f,  1.0f,  1.0f},
		glm::vec3{-1.0f,  1.0f,  1.0f},

		glm::vec3{-1.0f, -1.0f,  1.0f},
		glm::vec3{ 1.0f, -1.0f,  1.0f},
		glm::vec3{ 1.0f,  1.0f,  1.0f},
		glm::vec3{-1.0f,  1.0f,  1.0f},
		
		glm::vec3{-1.0f, -1.0f, -1.0f},
		glm::vec3{ 1.0f, -1.0f, -1.0f},
		glm::vec3{ 1.0f,  1.0f, -1.0f},
		glm::vec3{-1.0f,  1.0f, -1.0f},

		glm::vec3{-1.0f, -1.0f, -1.0f},
		glm::vec3{-1.0f, -1.0f,  1.0f},
		glm::vec3{-1.0f,  1.0f,  1.0f},
		glm::vec3{-1.0f,  1.0f, -1.0f},

		glm::vec3{ 1.0f, -1.0f, -1.0f},
		glm::vec3{ 1.0f, -1.0f,  1.0f},
		glm::vec3{ 1.0f,  1.0f,  1.0f},
		glm::vec3{1.0f,  1.0f, -1.0f}
	};

	texCoords = {
		glm::vec2{0.25f, 0.23f},
		glm::vec2{0.5f, 0.1f},
		glm::vec2{0.5f, 0.28f},
		glm::vec2{0.25f, 0.43f},
		
		glm::vec2{0.10f, 0.67f},
		glm::vec2{0.5f, 0.5f},
		glm::vec2{0.5f, 0.9f},
		glm::vec2{0.5f, 0.7f},

		glm::vec2{0.25f, 0.23f},
		glm::vec2{0.5f, 0.1f},
		glm::vec2{0.5f, 0.5f},
		glm::vec2{0.25f, 0.67f},

		glm::vec2{0.25f, 0.23f},
		glm::vec2{0.5f, 0.1f},
		glm::vec2{0.5f, 0.5f},
		glm::vec2{0.25f, 0.67f},

		glm::vec2{0.25f, 0.23f},
		glm::vec2{0.5f, 0.1f},
		glm::vec2{0.5f, 0.5f},
		glm::vec2{0.25f, 0.67f},

		glm::vec2{0.25f, 0.23f},
		glm::vec2{0.5f, 0.1f},
		glm::vec2{0.5f, 0.5f},
		glm::vec2{0.25f, 0.67f},
	};

	indices = {
		// Bottom Face
		0, 1, 2,   0, 2, 3,
		// Top Face
		4, 5, 6,   4, 6, 7,
		// Front Face
		8, 9, 10,  8, 10, 11,
		// Back Face
		12, 13, 14,  12, 14, 15,
		// Left Face
		16, 17, 18,  16, 18, 19,
		// Right Face
		20, 21, 22,  20, 22, 23
	};

	cubeRender = new RenderComponent(vertices, indices, texCoords, texID);
}

Cube::~Cube()
{
}