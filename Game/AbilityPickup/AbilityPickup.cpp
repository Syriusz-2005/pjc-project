
#include "AbilityPickup.h"
#include "../States/States.h"

AbilityPickup::AbilityPickup(TextureLoader<TextureId> const* loader, const std::string &uid)
    : TexturedRect(
            PhysicsModule(0, 0, 0, true),
            uid,
            *loader->getTexture(ABILITY),
            sf::Vector2f{0, 0},
            BACKGROUND
            ) {

}

bool AbilityPickup::onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) {
    Object::onBeforeCollision(collisionTarget);
    if (collisionTarget->getType() == PLAYER) {
        parent->state.set(IS_PICKING_UP_DOUBLE_JUMP_ABILITY, true);
        willDispose = true;
    }
    return true;
}
