
#include "PhysicsModule.h"
#include "fmt/core.h"

PhysicsModule::PhysicsModule(
        const float mass,
        const float gravity,
        const float bounciness) : mass(mass), gravity(gravity), bounciness(bounciness) {

}

void PhysicsModule::load(nlohmann::json const& json) {
    mass = json["mass"];
    gravity = json["gravity"];
    isImmovable = json["isImmovable"];
    isEthereal = json["isEthereal"];
    bounciness = json["bounciness"];
    isOnGround = json["isOnGround"];
}

std::unique_ptr<nlohmann::json> PhysicsModule::save() {
    auto json = std::make_unique<nlohmann::json>();
    (*json)["mass"] = mass;
    (*json)["gravity"] = gravity;
    (*json)["isImmovable"] = isImmovable;
    (*json)["isEthereal"] = isEthereal;
    (*json)["bounciness"] = bounciness;
    (*json)["isOnGround"] = isOnGround;
    return json;
}
