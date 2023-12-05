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

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
}

void Renderer::Clear() const {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw() const {
    // Implement drawing code here

    // Example vertex data for a rectangle (two triangles)
    float vertices[] = {
        // Positions         // Colors
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  // Top Right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  // Bottom Right
       -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  // Bottom Left
       -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f   // Top Left 
    };

    // Generate and bind a Vertex Array Object (VAO)
    VertexArray VAO;
    VertexBuffer VBO(vertices, sizeof(vertices));

    //VAO.Bind();
    VBO.Bind();

    // Example indices for the EBO
    GLuint indices[] = {
        0, 1, 2, // First Triangle
        0, 2, 3  // Second Triangle
    };

    ElementBuffer EBO(indices, 6);

    // Assuming vertices are structured as 3 floats for position, then 3 floats for color
    VertexAttribute positionAttrib(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    VertexAttribute colorAttrib(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    // Draw the triangle
    shader->Use();
    VAO.Bind();
    EBO.Bind();
    VAO.AddAttribute(positionAttrib);
    VAO.AddAttribute(colorAttrib);

    glDrawElements(GL_TRIANGLES, EBO.GetCount(), GL_UNSIGNED_INT, 0);

    // Cleanup
    VAO.Unbind();
    VBO.Unbind();
    EBO.Unbind();
}

void Renderer::SwapBuffers(GLFWwindow* window) const {
    // Swap front and back buffers
    glfwSwapBuffers(window);
}

void Renderer::setShaders(const char* vertexShader, const char* fragmentShader)
{
    shader = new Shader(vertexShader, fragmentShader);
}
