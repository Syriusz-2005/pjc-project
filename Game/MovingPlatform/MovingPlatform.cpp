
#include "MovingPlatform.h"
#include "../../Engine/VecUtils/VecUtils.h"
#include "../ObjectType/ObjectType.h"

MovingPlatform::MovingPlatform(std::string const& uid)
: Rect(PhysicsModule(0, 0, 0), uid, sf::Vector2f{150, 40}) {
    physicsModule.isImmovable = true;
}

void MovingPlatform::onBeforeStep(long long timeElapsed) {
    Object::onBeforeStep(timeElapsed);
    currentState += ((float) timeElapsed / 1000) * speed;
    auto finalPos = vec::mix(pos1, pos2, std::sin( currentState) * .5 + 1);
    prevPos = pos;
    pos = finalPos;
}

void MovingPlatform::onAfterCollision(const std::shared_ptr<Object> &collisionTarget) {
    Object::onAfterCollision(collisionTarget);

    if (!collisionTarget->physicsModule.isImmovable and collisionTarget->physicsModule.isOnGround) {
        auto posDelta = pos - prevPos;
        collisionTarget->move(sf::Vector2f{posDelta.x, posDelta.y > 0 ? posDelta.y: 0});
    }

}



auto MovingPlatform::setCurrentState(float newState) -> void {
    currentState = newState;
}

std::unique_ptr<nlohmann::json> MovingPlatform::save() {
    auto json = Object::save();
    (*json)["currentState"] = currentState;
    return json;
}

void MovingPlatform::load(const nlohmann::json &json) {
    Object::load(json);
    currentState = json["currentState"];
}


