
#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "../../Engine/Group/Group.h"
#include "../../Engine/Rect/Rect.h"

class Player : public Object {
private:
    short horizontalMovement = 0;
    Rect pRect = Rect(PhysicsModule(0, 0));
    bool willJump = false;

    auto onKeyPress(sf::Event event) -> void;
    auto onKeyRelease(sf::Event event) -> void;
public:
    explicit Player();

    auto dispatchEvents(sf::RenderWindow& window) -> void;
    auto getBoundingBox() -> sf::FloatRect override;
    auto render(Context ctx) -> void override;
    void onBeforeStep() override;

    ~Player() override;
};


#endif //PJC_PROJECT_PLAYER_H
