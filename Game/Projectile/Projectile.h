
#ifndef PJC_PROJECT_PROJECTILE_H
#define PJC_PROJECT_PROJECTILE_H


#include "../../Engine/Object/Object.h"

class Projectile : public Object {
    int despawnTimeMs{6000};
    sf::CircleShape shape{};

public:
    explicit Projectile(std::string const& uid, sf::Vector2f const& initialPos, sf::Vector2f const&target);

    void onBeforeStep(long long timeElapsed) override;
    sf::FloatRect getBoundingBox() override;
    bool onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) override;
    void render(Context ctx) override;
};


#endif //PJC_PROJECT_PROJECTILE_H
