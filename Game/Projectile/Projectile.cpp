
#include "Projectile.h"
#include "../../Engine/VecUtils/VecUtils.h"

Projectile::Projectile(const std::string &uid, const sf::Vector2f &initialPos, const sf::Vector2f &target)
    : Object(
        PhysicsModule(1, 0, 1),
        uid
    ) {
    name = "Projectile";
    isSavable = false;
    setPos(initialPos);
    auto direction = vec::normalize(target - initialPos);
    vel = vec::multiply(direction, 0.3);
    shape.setFillColor(sf::Color(0, 0, 0));
}

void Projectile::onBeforeStep(long long int timeElapsed) {
    Object::onBeforeStep(timeElapsed);

    despawnTimeMs -= (int) (timeElapsed / 1000);
    if (despawnTimeMs <= 0) {
        fmt::println("Disposing projectile");
        willDispose = true;
    }
}

sf::FloatRect Projectile::getBoundingBox() {
    return sf::FloatRect{pos, sf::Vector2f{30, 30}};
}

bool Projectile::onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) {
    Object::onBeforeCollision(collisionTarget);

    if (collisionTarget->getType() == FLY) {
        return false;
    }

    if (collisionTarget->getType() == PLAYER) {
        collisionTarget->applyDamage(20);
        willDispose = true;
        return false;
    }

    return true;
}

void Projectile::render(Context ctx) {
    auto cameraSpacePos = ctx.globalPos + pos;
    shape.setPosition(cameraSpacePos);
    shape.setRadius(15);
    ctx.window->draw(shape);
}
