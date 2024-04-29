//
// Created by NOWY on 29.04.2024.
//

#include "GroundPlatformSmall.h"

GroundPlatformSmall::GroundPlatformSmall(const TextureLoader<TextureId> &loader) : TexturedRect(
        PhysicsModule(),
        *loader.getTexture(GROUND_PLATFORM_SMALL),
        sf::Vector2f(0, -130),
        FOREGROUND) {
    physicsModule.isImmovable = true;
    name = "Ground";
}
