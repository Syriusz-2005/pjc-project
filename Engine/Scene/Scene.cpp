
#include "Scene.h"

Scene::Scene(sf::Color clearColor): clearColor(clearColor), physicsEngine(PhysicsEngine(objects)) {

}

auto Scene::render(Context ctx) -> void {
    ctx.window->clear(clearColor);
    for (const auto& object : objects) {
        object->render(ctx);
    }
}


auto Scene::getObjects() -> std::vector<std::shared_ptr<Object>>& {
    return objects;
}

auto Scene::getPhysicsEngine() -> PhysicsEngine const & {
    return physicsEngine;
}
