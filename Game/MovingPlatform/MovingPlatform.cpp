
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

bool MovingPlatform::onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) {
    Object::onBeforeCollision(collisionTarget);
    if (!collisionTarget->physicsModule.isImmovable and collisionTarget->physicsModule.isOnGround) {
        auto posDelta = pos - prevPos;
        collisionTarget->move(posDelta);
    }


    return true;
}
