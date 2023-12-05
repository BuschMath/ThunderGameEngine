#include "Window.h"
#include <iostream>

Window::Window(int width, int height, const char* title) {
    Initialize(width, height, title);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::Initialize(int width, int height, const char* title) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
}

bool Window::IsOpen() const {
    return !glfwWindowShouldClose(window);
}

void Window::ProcessInput() const {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

GLFWwindow* Window::GetGLFWwindow() const {
    return window;
}

void Window::PollEvents() const
{
    glfwPollEvents();
}
