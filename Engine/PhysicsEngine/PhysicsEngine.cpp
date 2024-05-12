

#include "../Scene/Scene.h"
#include "PhysicsEngine.h"
#include <fmt/core.h>
#include <cmath>

PhysicsEngine::PhysicsEngine(std::vector<std::shared_ptr<Object>> &objects): objects(&objects) {

}

auto PhysicsEngine::step(long long timeElapsed) const -> void {
    auto deltaMs = ((float) timeElapsed) / 1000;
    for (auto it = objects->begin(); it != objects->end(); it++) {
        const auto object = *it;
        object->onBeforeStep(timeElapsed);
        if (object->getLayer() == BACKGROUND) continue;
        auto module = object->physicsModule;
        if (module.isImmovable) continue;
        auto vel = object->getVel();
        vel.y += module.gravity * deltaMs;
        object->setVel(vel);
        object->move(vel * deltaMs);
        applyCollision(object);
        object->onAfterStep();
    }
}

auto PhysicsEngine::getIntersectionArea(sf::Rect<float> a, sf::Rect<float> b) -> sf::Rect<float>* {
    auto topLeftA = a.getPosition();
    auto topLeftB = b.getPosition();

    auto bottomRightA = topLeftA + a.getSize();
    auto bottomRightB = topLeftB + b.getSize();

    float x1 = std::max(topLeftA.x, topLeftB.x);
    float y1 = std::max(topLeftA.y, topLeftB.y);

    float x2 = std::min(bottomRightA.x, bottomRightB.x);
    float y2 = std::min(bottomRightA.y, bottomRightB.y);

    if (x2 - x1 > 0 && y2 - y1 > 0) {
        return new sf::Rect<float>(sf::Vector2f(x1, y1), sf::Vector2f(x2 - x1, y2 - y1));
    }

    return nullptr;
}

auto PhysicsEngine::applyCollisionForces(Object& a, Object& b, sf::FloatRect const&i) const -> void {
    auto mA = a.physicsModule;
    auto mB = b.physicsModule;
    float aCommitment = mB.isImmovable ? 1 : (mA.mass < mB.mass ? 1 - (mA.mass / mB.mass) : mB.mass - mA.mass);
    float bCommitment = 1 - aCommitment;

    auto aPos = getMiddlePos(a);
    auto iPos = getMiddlePos(i);

    auto aNewPos = a.getPos();
    auto bNewPos = b.getPos();

    if (i.width < i.height) {
        auto rvx = (a.getVel().x + b.getVel().x);
        float direction = iPos.x < aPos.x ? 1 : -1;
        aNewPos.x += i.width * direction * aCommitment;
        bNewPos.x += i.width * direction * bCommitment;
        a.setVelX(-rvx * aCommitment * mA.bounciness);
        b.setVelX(rvx * bCommitment * mB.bounciness);
    } else {
        auto rvy = (a.getVel().y + b.getVel().y);
        float direction = iPos.y < aPos.y ? 1 : -1;
        aNewPos.y += i.height * aCommitment * direction;
        bNewPos.y += i.height * bCommitment * direction;
        a.setVelY(-rvy * aCommitment * mA.bounciness);
        b.setVelY(rvy * bCommitment * mB.bounciness);
    }

    a.setPos(aNewPos);
    b.setPos(bNewPos);
}


/**
 * TODO: Use continues collision detection to fix some "edge" cases:)
 * TODO: Use some kind of a spatial hash grid or something similar to improve performance for large scenes
 * Applies collision forces to the provided object and the object it collides with
 * Based on my previous implementation of the collision system in java: https://github.com/Syriusz-2005/java-ping-pong-poc/blob/main/src/main/java/Physics/PhysicsScene.java
 * @param o
 */
auto PhysicsEngine::applyCollision(std::shared_ptr<Object> o) const -> void {
    auto module = &o->physicsModule;
    if (module->isEthereal || module->isImmovable) return;

    auto oBox = o->getBoundingBox();
    // Why not a range based loop?
    // Because I don't understand c++
    // Using a range-based loop may cause an undefined behaviour when one of the children removes something from the scene
    // For example Spikes destroy an object that collides with them in the onBeforeCollision method. Range based loop will crash the program in such scenario.
    for (auto it = objects->begin(); it != objects->end(); it++) {
        const auto neighbour = *it;
        auto nModule = neighbour->physicsModule;
        if (!nModule.isEthereal && neighbour != o) {
            auto nBox = neighbour->getBoundingBox();
            auto intersectionArea = getIntersectionArea(oBox, nBox);
            if (intersectionArea) {
                auto continued = o->onBeforeCollision(neighbour);
                if (!continued) continue;
                auto neighbourContinued = neighbour->onBeforeCollision(o);
                if (!neighbourContinued) continue;
                if (neighbour->getLayer() == BACKGROUND) continue;
                applyCollisionForces(*o, *neighbour, *intersectionArea);
                o->onAfterCollision(neighbour);
                neighbour->onAfterCollision(o);
                if (std::abs(o->getVel().y) < .01 and intersectionArea->width > intersectionArea->height) {
                    module->isOnGround = true;
                }
                delete intersectionArea;
            }
        }
    }

    if (std::abs(o->getVel().y) > .01) {
        module->isOnGround = false;
    }
}

auto PhysicsEngine::getMiddlePos(Object &o) const -> sf::Vector2f {
    return getMiddlePos(o.getBoundingBox());
}

auto PhysicsEngine::getMiddlePos(sf::FloatRect rect) const -> sf::Vector2f {
    return rect.getPosition() + (sf::Vector2f(rect.width / 2, rect.height / 2));
}
