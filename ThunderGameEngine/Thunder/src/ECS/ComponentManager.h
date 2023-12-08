// ComponentManager.h
#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include <typeindex>
#include <memory>
#include <stdexcept>
#include <vector>
#include "Entity.h"
#include "Component.h"  // Include the base Component class or specific component classes

class ComponentManager {
public:
    template<typename T>
    void AddComponent(Entity entity, T component) {
        auto componentPtr = std::make_shared<T>(component);
        components[std::type_index(typeid(T))][entity.GetID()] = componentPtr;
    }

    template<typename T>
    T& GetComponent(Entity entity) {
        if (HasComponent<T>(entity)) {
            return *std::static_pointer_cast<T>(components[std::type_index(typeid(T))][entity.GetID()]);
        }
        throw std::runtime_error("Component not found on entity!");
    }

    template<typename T>
    bool HasComponent(Entity entity) {
        auto mapIt = components.find(std::type_index(typeid(T)));
        if (mapIt != components.end()) {
            return mapIt->second.find(entity.GetID()) != mapIt->second.end();
        }
        return false;
    }

    template<typename T>
    void RemoveComponent(Entity entity) {
        components[std::type_index(typeid(T))].erase(entity.GetID());
    }

    template<typename T>
    std::vector<Entity> GetAllEntitiesWithComponent() {
        std::vector<Entity> entities;
//std::cout << "type_index: " << std::type_index(typeid(T)).name() << std::endl;
        for(auto& component : components[std::type_index(typeid(T))]) {
            Entity::ID id = component.first;
            Entity entity(id);
            entities.push_back(entity);
		}
		return entities;
    }

private:
    std::unordered_map<std::type_index, std::unordered_map<Entity::ID, std::shared_ptr<void>>> components;
};

#endif // COMPONENTMANAGER_H

