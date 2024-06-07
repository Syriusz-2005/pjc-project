
#include "Fly.h"
#include "../Projectile/Projectile.h"

Fly::Fly(TextureLoader<TextureId> const &loader, std::string const&uid)
    : TexturedRect(
        PhysicsModule(1, 0, 1, false),
        uid,
        *loader.getTexture(FLYING_ENTITY),
        sf::Vector2f{0, 0}
    ) {
    name = "Fly enemy";
    setType(FLY);
}

void Fly::onBeforeStep(long long int timeElapsed) {
    Object::onBeforeStep(timeElapsed);

    if (vec::length(spawnPos) == 0) {
        spawnPos = pos;
        setNewTarget();
    }

    auto dir = vec::normalize(pathTarget - pos);
    vel = vec::multiply(dir, 0.1);

    if (vec::distance(pos, pathTarget) <= vec::length(vel)) {
        setNewTarget();
    }

    auto& player = parent->get("player0");
    auto distanceToPlayer = vec::distance(player->getPos(), pos);
    if (distanceToPlayer < 800) {
        shootDelayMs -= (int) (timeElapsed / 1000);
        if (shootDelayMs <= 0) {
            auto newProjectile = std::make_shared<Projectile>(getUid() + "_projectile_" + std::to_string(lastProjectileIndex), pos, player->getPos());
            parent->add(newProjectile);
            lastProjectileIndex++;
            shootDelayMs = 3000;
        }
    }
}

auto Fly::setNewTarget() -> void {
    auto t = vec::rand(spawnPos, 200);
    pathTarget = t;
}
