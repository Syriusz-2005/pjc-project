

#include "Ground.h"

Ground::Ground(TextureLoader<TextureId> const& loader)
: TexturedRect(
        PhysicsModule(),
        *loader.getTexture(GROUND),
        sf::Vector2f(0, -190),
        FOREGROUND) {
    physicsModule.isImmovable = true;
    name = "Ground";
}
