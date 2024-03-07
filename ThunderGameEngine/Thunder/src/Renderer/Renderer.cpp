#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include <iostream>

Renderer::Renderer() {
    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return;
    }

    shader = nullptr;
    renderSystem = nullptr;

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
}

void Renderer::Clear() const {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw() const {
    // Implement drawing code here
    renderSystem->Update();
}

void Renderer::SwapBuffers(GLFWwindow* window) const {
    // Swap front and back buffers
    glfwSwapBuffers(window);
}

void Renderer::setShaders(const char* vertexShader, const char* fragmentShader)
{
    shader = new Shader(vertexShader, fragmentShader);
}

void Renderer::setComponentManager(ComponentManager* componentManager)
{
    p_componentManager = componentManager;
}

void Renderer::setRenderSystem()
{
	renderSystem = new RenderSystem(*p_componentManager, *shader);
}

void Renderer::setRenderSystem2D()
{
    renderSystem = new RenderSystem2D(*p_componentManager, *shader);
}
