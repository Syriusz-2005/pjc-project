
#ifndef PJC_PROJECT_SCENE_H
#define PJC_PROJECT_SCENE_H

#include <vector>
#include "../Object/Object.h"
#include "../PhysicsEngine/PhysicsEngine.h"

class Scene {
private:
    std::vector<Object*> objects = std::vector<Object*>();
    sf::Color clearColor;
    PhysicsEngine physicsEngine;

public:
    explicit Scene(sf::Color clearColor);
    auto add(Object& o) -> void;
    auto render(Context ctx) -> void;
    auto getObjects() -> std::vector<Object*>&;
    auto getPhysicsEngine() -> PhysicsEngine const&;
};


#endif //PJC_PROJECT_SCENE_H
