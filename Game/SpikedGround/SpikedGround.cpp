

#include "SpikedGround.h"

SpikedGround::SpikedGround(TextureLoader<TextureId> const& loader, std::string uid)
        : TexturedRect(
        PhysicsModule(),
        uid,
        *loader.getTexture(SPIKES_GROUND),
        sf::Vector2f(0, -190),
        FOREGROUND) {
    physicsModule.isImmovable = true;
    name = "Spiked ground";
}

bool SpikedGround::onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) {
    collisionTarget->applyDamage(1);
    return true;
}
