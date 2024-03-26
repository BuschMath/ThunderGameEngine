#include "Engine.h"
#include "ECS/RenderComponent3D.h"
#include "ECS/CameraComponent.h"
#include "ECS/TransformComponent.h"

char cubeTexturePath[] = "C:/Users/busch/OneDrive - Iowa Central Community College/Computer_Code/ThunderGameEngine/ThunderGameEngine/Thunder/src/Utility/GrassDirtCube.jpg";

int main() {
    Engine engine(1600, 1200, "Thunder Game Engine");

	Entity cube = engine.CreateCube(cubeTexturePath);

	Entity camera = engine.CreateCamera(glm::vec3(3, 4, 4), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), 
		60.0f, 1600.0f / 1200.0f, 0.1f, 100.0f);

    engine.Run();

    return 0;
}
