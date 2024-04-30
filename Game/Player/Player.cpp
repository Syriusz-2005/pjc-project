
#include "Player.h"
#include "../../Engine/VecUtils/VecUtils.h"
#include <algorithm>
#include "../ObjectType/ObjectType.h"

Player::Player(InitContext ctx, std::string uid)
        : Object(
        PhysicsModule(1, 0.00043, 0),
        uid,
        FOREGROUND) {
    name = "Player object";
    auto texture = ctx.textureLoader->getTexture(PLAYER_STILL);
    sprite = sf::Sprite(*texture);
    sprite.setScale(0.068, 0.068);
    setEntityModule(entityModule);
    setType(PLAYER);
}

auto Player::dispatchEvents(sf::RenderWindow &window) -> void {
    auto event = sf::Event();
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::KeyPressed:
                onKeyPress(event);
                break;
            case sf::Event::KeyReleased:
                onKeyRelease(event);
                break;
            default: {
            }
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
        default: {
        }
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
        default: {
        }
    }
}

auto Player::getBoundingBox() -> sf::FloatRect {
    return sf::FloatRect{pos, sf::Vector2f(40, 80)};
}

auto Player::render(Context ctx) -> void {
    auto screenPos = ctx.globalPos + pos;
    sprite.setPosition(screenPos);
    ctx.window->draw(sprite);
}

void Player::onBeforeStep() {
    if (willJump) {
        willJump = false;
        if (physicsModule.isOnGround) {
            vel.y -= .35;
        }
    }

    if (physicsModule.isOnGround) {
        vel.x = (float) (horizontalMovement * 0.14);
    } else {
        auto finalVel = (double) vel.x;
        auto sign = vel.x > 0 ? 1 : -1;
        auto xSpeed = std::abs(vel.x == 0 ? 0.1 : vel.x) * 140;
        auto multiplier = 0.0004 * (1 / xSpeed);
        finalVel += horizontalMovement * multiplier;

        if (horizontalMovement == 0) {
            finalVel -= sign * 0.00001; // air friction
        }

        vel.x = (float) std::clamp(finalVel, -.14, .14);
    }

}

auto Player::setSpawnPoint() -> void {
    spawnPoint = pos;
}

void Player::load(nlohmann::json const &json) {
    Object::load(json);
    spawnPoint.x = json["spawnPoint"]["x"];
    spawnPoint.y = json["spawnPoint"]["y"];
}

std::unique_ptr<nlohmann::json> Player::save() {
    auto json = Object::save();
    (*json)["spawnPoint"]["x"] = spawnPoint.x;
    (*json)["spawnPoint"]["y"] = spawnPoint.y;
    return json;
}
