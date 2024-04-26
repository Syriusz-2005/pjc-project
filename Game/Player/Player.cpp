
#include "Player.h"
#include "../../Engine/Rect/Rect.h"

Player::Player(): Object(PhysicsModule(1, 0.0003, 0), FOREGROUND) {
    pRect.physicsModule.isImmovable = true;
    pRect.physicsModule.bounciness = 0;
    pRect.physicsModule.isEthereal = true;
    pRect.name = "Player rect";
    name = "Player object";
}

auto Player::dispatchEvents(sf::RenderWindow& window) -> void {
    auto event = sf::Event();
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::KeyPressed: onKeyPress(event); break;
            case sf::Event::KeyReleased: onKeyRelease(event); break;
            default: {}
        }
    }
}

auto Player::onKeyPress(sf::Event event) -> void {
    switch (event.key.code) {
        case sf::Keyboard::A: {
            horizontalMovement = -1;
            break;
        }
        case sf::Keyboard::D: {
            horizontalMovement = 1;
            break;
        }
        default: {}
    }
}

auto Player::onKeyRelease(sf::Event event) -> void {
    switch (event.key.code) {
        case sf::Keyboard::A: {
            horizontalMovement = 0;
            break;
        }
        case sf::Keyboard::D: {
            horizontalMovement = 0;
            break;
        }
        default: {}
    }
}

auto Player::getBoundingBox() -> sf::FloatRect {
    return sf::FloatRect{pos, sf::Vector2f(40, 40)};
}

auto Player::render(Context ctx) -> void {
    ctx.globalPos += pos;
    pRect.render(ctx);
}

void Player::onBeforeStep() {
//    fmt::println("{}, {}", physicsModule.isOnGround, horizontalMovement);
    if (horizontalMovement != 0 and not physicsModule.isOnGround) return;
    vel.x = (float) horizontalMovement * 0.1;
}
