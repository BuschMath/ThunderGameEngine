#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include <unordered_set>

class EntityManager {
public:
    Entity CreateEntity();
    void DestroyEntity(Entity entity);
    bool IsEntityValid(Entity entity) const;

private:
    std::unordered_set<Entity::ID> validEntities;
};

#endif // ENTITYMANAGER_H

