
#ifndef PJC_PROJECT_SCENE_H
#define PJC_PROJECT_SCENE_H

#include <vector>
#include "../Object/Object.h"
#include "../PhysicsEngine/PhysicsEngine.h"

class Scene {
private:
    std::vector<std::shared_ptr<Object>> objects = std::vector<std::shared_ptr<Object>>();
    sf::Color clearColor;
    PhysicsEngine physicsEngine;

public:
    explicit Scene(sf::Color clearColor);
    template <typename T>
    auto add(std::shared_ptr<T> o) -> void {
        objects.push_back(o);
    }
    auto render(Context ctx) -> void;
    auto getObjects() -> std::vector<std::shared_ptr<Object>>& ;
    auto getPhysicsEngine() -> PhysicsEngine const&;

};


#endif //PJC_PROJECT_SCENE_H
