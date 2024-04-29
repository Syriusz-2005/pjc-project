
#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "../../Engine/Group/Group.h"
#include "../../Engine/Rect/Rect.h"
#include "../InitContext/InitContext.h"

class Player : public Object {
private:
    short horizontalMovement = 0;
    sf::Sprite sprite;
    bool willJump = false;
    sf::Vector2f spawnPoint;

    auto onKeyPress(sf::Event event) -> void;
    auto onKeyRelease(sf::Event event) -> void;
public:
    explicit Player(InitContext ctx);

    auto dispatchEvents(sf::RenderWindow& window) -> void;
    auto setSpawnPoint() -> void;

    auto getBoundingBox() -> sf::FloatRect override;
    auto render(Context ctx) -> void override;
    void onBeforeStep() override;
    void applyDamage(float damageValue) override;
};


#endif //PJC_PROJECT_PLAYER_H
