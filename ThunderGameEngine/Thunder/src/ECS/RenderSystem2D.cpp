#include "RenderSystem2D.h"

void RenderSystem2D::Update() {
    // Iterate through all entities that have a RenderComponent2D
    // This example assumes you have a way to get such entities
    std::vector<Entity> entities = componentManager.GetAllEntitiesWithComponent<RenderComponent2D>();
    for (const Entity& entity : entities) {
        RenderEntity(entity);
    }
}

void RenderSystem2D::RenderEntity(const Entity& entity) {
    // Get the RenderComponent2D of the entity
    const RenderComponent2D& renderComponent = componentManager.GetComponent<RenderComponent2D>(entity);

    // Set up your rendering logic here
    // For example, bind the shader, set up the vertex data and draw

    shader.Use();
    // Here you would typically bind the VAO, set up vertex attributes, and draw
    // This might involve creating VBOs, VAOs, and EBOs for the renderComponent data if not already created
    // An example would be glDrawArrays or glDrawElements, depending on your data
}
