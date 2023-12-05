
const char* vertexShaderLoc = "C:/Users/busch/OneDrive - Iowa Central Community College/Computer_Code/ThunderGameEngine/ThunderGameEngine/Thunder/src/Renderer/vertex_shader.vert";
const char* fragmentShaderLoc = "C:/Users/busch/OneDrive - Iowa Central Community College/Computer_Code/ThunderGameEngine/ThunderGameEngine/Thunder/src/Renderer/fragment_shader.frag";

#include "Renderer/Renderer.h"
#include "Renderer/Window.h"

int main() {
    Window window(800, 600, "Thunder Engine");
    Renderer renderer;
    renderer.setShaders(vertexShaderLoc, fragmentShaderLoc);

    while (window.IsOpen()) {
        window.ProcessInput();

        renderer.Clear();
        renderer.Draw();
        renderer.SwapBuffers(window.GetGLFWwindow());
        window.PollEvents();
    }

    return 0;
}
