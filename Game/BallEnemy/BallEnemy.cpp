//
// Created by NOWY on 30.04.2024.
//

#include "BallEnemy.h"

BallEnemy::BallEnemy(TextureLoader<TextureId> const& loader, std::string const& uid)
: TexturedRect(
        PhysicsModule(),
        uid,
        *loader.getTexture(ENEMY_BALL),
        sf::Vector2f(0, 0),
        FOREGROUND
        ) {
    name = "Ball enemy";
    setEntityModule(entityModule);
}
