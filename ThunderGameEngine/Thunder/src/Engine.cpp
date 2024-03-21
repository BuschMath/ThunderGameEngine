
const char* vertexShaderLoc = "C:/Users/busch/OneDrive - Iowa Central Community College/Computer_Code/ThunderGameEngine/ThunderGameEngine/Thunder/src/Renderer/vertex_shader.vert";
const char* fragmentShaderLoc = "C:/Users/busch/OneDrive - Iowa Central Community College/Computer_Code/ThunderGameEngine/ThunderGameEngine/Thunder/src/Renderer/fragment_shader.frag";

#include "Engine.h"

Engine::Engine(int winHeight, int winWidth, const char* winTitle) : m_winHeight(winHeight), 
    m_winWidth(winWidth), m_winTitle(winTitle)
{
    p_window = new Window(winHeight, winWidth, winTitle);
    p_renderer = new Renderer();
    p_renderer->setShaders(vertexShaderLoc, fragmentShaderLoc);
    p_entityManager = new EntityManager();
    p_componentManager = new ComponentManager();
    p_renderer->setComponentManager(p_componentManager);
    p_renderer->setRenderSystem();
}

Engine::~Engine()
{
}

Entity Engine::CreateEntity()
{
    return p_entityManager->CreateEntity();
}

void Engine::Run()
{
    glEnable(GL_DEPTH_TEST);

    while (p_window->IsOpen()) {
        p_window->ProcessInput();

        p_renderer->Clear();
        p_renderer->Draw();
        p_renderer->SwapBuffers(p_window->GetGLFWwindow());
        p_window->PollEvents();
    }
}
