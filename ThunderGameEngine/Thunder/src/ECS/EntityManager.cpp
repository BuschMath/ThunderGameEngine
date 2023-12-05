#include "EntityManager.h"

Entity EntityManager::CreateEntity() {
    Entity newEntity;
    validEntities.insert(newEntity.GetID());
    return newEntity;
}

void EntityManager::DestroyEntity(Entity entity) {
    validEntities.erase(entity.GetID());
}

bool EntityManager::IsEntityValid(Entity entity) const {
    return validEntities.find(entity.GetID()) != validEntities.end();
}
