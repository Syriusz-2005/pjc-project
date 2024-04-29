
#include "PhysicsModule.h"

PhysicsModule::PhysicsModule(
        const float mass,
        const float gravity,
        const float bounciness) : mass(mass), gravity(gravity), bounciness(bounciness) {

}

void PhysicsModule::load(nlohmann::json json) {
    mass = json["mass"];
    gravity = json["gravity"];
    isImmovable = json["isImmovable"];
    isEthereal = json["isEthereal"];
    bounciness = json["bounciness"];
    isOnGround = json["isOnGround"];
}

nlohmann::json PhysicsModule::save() {
    auto json = nlohmann::json();
    json["mass"] = mass;
    json["gravity"] = gravity;
    json["isImmovable"] = isImmovable;
    json["isEthereal"] = isEthereal;
    json["bounciness"] = bounciness;
    json["isOnGround"] = isOnGround;
    return json;
}
