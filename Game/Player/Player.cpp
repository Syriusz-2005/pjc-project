
#include "Player.h"
#include "../../Engine/Rect/Rect.h"
#include <algorithm>
#include <cmath>

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
        case sf::Keyboard::Space: {
            willJump = true;
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
    if (willJump) {
        willJump = false;
        if (physicsModule.isOnGround) {
            vel.y -= .2;
        }
    }

    if (physicsModule.isOnGround) {
        vel.x = (float) horizontalMovement * 0.1;
    } else {
        auto finalVel = (double) vel.x;
        auto sign = vel.x > 0 ? 1 : -1;
        auto xSpeed = std::abs(vel.x == 0 ? 0.00000001 : vel.x) * 100;
        auto multiplier =  0.0004 * (1 / xSpeed);
        fmt::println("{}", multiplier);
        finalVel += horizontalMovement * multiplier;

        if (horizontalMovement == 0) {
            finalVel -= sign * 0.00001; // air friction
        }

        vel.x = std::clamp(finalVel, -.1, .1);
    }

}
