
#include "SpikeBallObstacle.h"

SpikeBallObstacle::SpikeBallObstacle(TextureLoader<TextureId> const& loader, std::string const& uid)
: TexturedRect(
        PhysicsModule(0, 0, 0),
        uid,
        *loader.getTexture(ENEMY_BALL),
        sf::Vector2f(0, 0),
        FOREGROUND
        ) {
    name = "Spike ball";
    physicsModule.isImmovable = true;
    boxSize = sf::Vector2f(55, 55);
}

bool SpikeBallObstacle::onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) {
    Object::onBeforeCollision(collisionTarget);
    Object::onBeforeCollision(collisionTarget);
    collisionTarget->applyDamage(20);
    return true;
}
