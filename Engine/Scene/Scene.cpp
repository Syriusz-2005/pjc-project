
#include "Scene.h"

Scene::Scene(sf::Color clearColor): clearColor(clearColor), physicsEngine(PhysicsEngine(objects)) {

}

auto Scene::add(Object &o) -> void {
    objects.push_back(&o);
}

auto Scene::render(Context ctx) -> void {
    ctx.window->clear(clearColor);
    for (auto object : objects) {
        object->render(ctx);
    }
}


auto Scene::getObjects() -> std::vector<Object *> & {
    return objects;
}

auto Scene::getPhysicsEngine() -> PhysicsEngine const & {
    return physicsEngine;
}
