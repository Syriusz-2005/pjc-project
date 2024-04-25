
#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "../../Engine/Group/Group.h"
#include "../../Engine/Rect/Rect.h"

class Player : public Group {
private:
    short horizontalMovement = 0;
    Rect pRect = Rect(PhysicsModule(0, 0));

    auto onKeyPress(sf::Event event) -> void;
    auto onKeyRelease(sf::Event event) -> void;
public:
    explicit Player(PhysicsModule const& module);

    auto dispatchEvents(sf::RenderWindow& window) -> void;
};


#endif //PJC_PROJECT_PLAYER_H
