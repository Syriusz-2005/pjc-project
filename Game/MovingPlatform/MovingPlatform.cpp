
#include "MovingPlatform.h"
#include "../../Engine/VecUtils/VecUtils.h"

MovingPlatform::MovingPlatform(std::string const& uid)
: Rect(PhysicsModule(0, 0, 0), uid, sf::Vector2f{150, 40}) {

}

void MovingPlatform::onBeforeStep(long long timeElapsed) {
    Object::onBeforeStep(timeElapsed);
    currentState += ((float) timeElapsed / 1000) * speed;
    auto finalPos = vec::mix(pos1, pos2, std::sin( currentState) * .5 + 1);
    pos = finalPos;
}
