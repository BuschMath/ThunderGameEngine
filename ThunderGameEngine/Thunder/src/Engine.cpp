
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

Entity Engine::CreateCamera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up, float fov, float aspectRatio, float nearClip, float farClip)
{
    // Calculate the forward, right, and up vectors
    glm::vec3 forward = glm::normalize(target - position);
    glm::vec3 right = glm::normalize(glm::cross(forward, up));
    glm::vec3 cameraUp = glm::cross(right, forward);

    // Create the lookAt matrix
    glm::mat4 lookAtMatrix = glm::mat4(1.0f);
    lookAtMatrix[0] = glm::vec4(right, 0.0f);
    lookAtMatrix[1] = glm::vec4(cameraUp, 0.0f);
    lookAtMatrix[2] = glm::vec4(-forward, 0.0f);

    // Convert the lookAt matrix into a quaternion
    glm::quat rotationQuaternion = glm::quat_cast(lookAtMatrix);

    // Create the camera entity
    Entity camera = CreateEntity();
    AddComponent(camera, CameraComponent(fov, aspectRatio, nearClip, farClip));
    AddComponent(camera, TransformComponent(position, rotationQuaternion, glm::vec3(1, 1, 1)));

    return camera;
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
