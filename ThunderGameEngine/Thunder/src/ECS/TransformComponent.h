#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/transform.hpp>

class TransformComponent : public Component 
{
public:
    TransformComponent(const glm::vec3& pos = glm::vec3(0.0f),
        const glm::quat& rot = glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
        const glm::vec3& scl = glm::vec3(1.0f))
        : position(pos), rotation(rot), scale(scl) {}

    void SetPosition(const glm::vec3& pos) { position = pos; }
    void SetRotation(const glm::quat& rot) { rotation = rot; }
    void SetScale(const glm::vec3& scl) { scale = scl; }

    const glm::vec3& GetPosition() const { return position; }
    const glm::quat& GetRotation() const { return rotation; }
    const glm::vec3& GetScale() const { return scale; }

    glm::mat4 GetModelMatrix() const {
        glm::mat4 posMatrix = glm::translate(position);
        glm::mat4 scaleMatrix = glm::scale(scale);
        glm::mat4 rotMatrix = glm::toMat4(rotation);

        // Model matrix: T * R * S
        return posMatrix * rotMatrix * scaleMatrix;
    }

private:
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;
};

#endif // TRANSFORMCOMPONENT_H

