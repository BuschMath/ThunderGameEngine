#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class Renderer {
public:
    Renderer();
    void Clear() const;
    void Draw() const;
    void SwapBuffers(GLFWwindow* window) const;

    void setShaders(const char* vertexShader, const char* fragmentShader);

private:
    Shader* shader;
};

#endif // RENDERER_H

