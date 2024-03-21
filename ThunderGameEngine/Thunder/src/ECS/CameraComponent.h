#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Component.h"

class CameraComponent : public Component
{
public:
    CameraComponent(float fov, float aspect, float nearPlane, float farPlane)
        : fov(fov), aspectRatio(aspect), nearPlane(nearPlane), farPlane(farPlane) {
        UpdateProjectionMatrix();
    }

    void UpdateProjectionMatrix() {
        projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    }

    glm::mat4 GetViewMatrix(const glm::vec3& position, const glm::quat& orientation) const {
        glm::mat4 view = glm::mat4_cast(glm::conjugate(orientation)); // Create view matrix from orientation
        view = glm::translate(view, -position); // Apply camera position
        return view;
    }

    const glm::mat4& GetProjectionMatrix() const { return projectionMatrix; }

private:
    float fov, aspectRatio, nearPlane, farPlane;
    glm::mat4 projectionMatrix;
};

#endif // CAMERACOMPONENT_H

