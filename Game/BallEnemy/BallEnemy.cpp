

#include "BallEnemy.h"
#include "../ObjectType/ObjectType.h"
#include "../../Engine/VecUtils/VecUtils.h"

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

void BallEnemy::onBeforeStep() {
    Object::onBeforeStep();
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
}
