#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>

class Entity {
public:
    using ID = std::uint32_t;

    Entity() : id(nextId++) {}
    explicit Entity(ID initId) : id(initId) {}

    ID GetID() const { return id; }

    bool operator==(const Entity& other) const { return id == other.id; }
    bool operator!=(const Entity& other) const { return id != other.id; }

private:
    ID id;
    static ID nextId;
};

#endif // ENTITY_H

