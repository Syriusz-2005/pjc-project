

#include "BallEnemy.h"
#include "../ObjectType/ObjectType.h"
#include "../../Engine/VecUtils/VecUtils.h"

BallEnemy::BallEnemy(TextureLoader<TextureId> const& loader, std::string const& uid)
: SpikeBallObstacle(
        loader,
        uid,
        PhysicsModule()
        ) {
    name = "Ball enemy";
    setEntityModule(entityModule);
    boxSize = sf::Vector2f(45, 45);
    shift = sf::Vector2f(50, 50);
}

void BallEnemy::onAfterStep() {
    Object::onAfterStep();
    auto children = parent->getChildren();
    for (const auto& child : children) {
        if (child->getType() == PLAYER) {
            auto distance = vec::distance(pos, child->getPos());
            if (distance < 650) {
                auto delta = child->getPos() - pos;
                vel.x = delta.x > 0 ? .09 : -.09;
            }
        }
    }

    auto size = vec::toFloat(sprite.getTexture()->getSize());
    sprite.setOrigin(vec::multiply(size, 1.0 / 2.0));
    sprite.rotate(vel.x * 10);
}