//
// Created by NOWY on 27.04.2024.
//

#include "Ground.h"

Ground::Ground(sf::Texture const& txt, sf::Vector2f const& shift): TexturedRect(PhysicsModule(), txt, shift, FOREGROUND) {
    physicsModule.isImmovable = true;
    name = "Ground";
}
