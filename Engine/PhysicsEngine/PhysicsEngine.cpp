

#include "../Scene/Scene.h"
#include "PhysicsEngine.h"
#include <fmt/core.h>

PhysicsEngine::PhysicsEngine(std::vector<Object *> &objects): objects(&objects) {

}

auto PhysicsEngine::step() -> void {
    for (auto object: *objects) {
        if (object->getLayer() == BACKGROUND) continue;
        auto module = object->physicsModule;
        auto vel = object->getVel();
        vel.y += module.gravity;
        object->setVel(vel);
        object->move(vel);
    }
}
