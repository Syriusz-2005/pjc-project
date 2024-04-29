

#include "SpikedGround.h"

SpikedGround::SpikedGround(TextureLoader<TextureId> const& loader)
        : TexturedRect(
        PhysicsModule(),
        *loader.getTexture(SPIKES_GROUND),
        sf::Vector2f(0, -190),
        FOREGROUND) {
    physicsModule.isImmovable = true;
    name = "Spiked ground";
}
