#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool IsOpen() const;
    void ProcessInput() const;
    GLFWwindow* GetGLFWwindow() const;
    void PollEvents() const;

private:
    GLFWwindow* window;

    void Initialize(int width, int height, const char* title);
};

#endif // WINDOW_H

