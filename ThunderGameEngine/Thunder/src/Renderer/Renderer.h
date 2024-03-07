#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "../ECS/RenderSystem.h"
#include "../ECS/RenderSystem2D.h"

class Renderer {
public:
    Renderer();
    void Clear() const;
    void Draw() const;
    void SwapBuffers(GLFWwindow* window) const;

    void setShaders(const char* vertexShader, const char* fragmentShader);
    void setComponentManager(ComponentManager* componentManager);
    void setRenderSystem();
    void setRenderSystem2D();

private:
    Shader* shader;
    RenderSystem* renderSystem;
    ComponentManager* p_componentManager;
};

#endif // RENDERER_H

