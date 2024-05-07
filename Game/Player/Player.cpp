#include "Player.h"
#include "../../Engine/VecUtils/VecUtils.h"
#include <algorithm>
#include "../ObjectType/ObjectType.h"
#include "../States/States.h"

Player::Player(InitContext ctx, std::string const& uid)
    : Object(PhysicsModule(1, 0.00043, 0), uid, FOREGROUND),
    animatedTxt(TextureSwitcher<TextureId>(*ctx.textureLoader, std::vector<TextureId>{PLAYER_STILL}, 60)),
    EventEmitter<PlayerEventType>() {
    name = "Player object";
    sprite = sf::Sprite();
    backlight.setTexture(*ctx.textureLoader->getTexture(BACKLIGHT));
    backlight.setScale(1.3, 2);
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
    emitScheduledMicrotasks();
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
            break;
        }
        case sf::Keyboard::W: {
            auto val = parent->state.get(IS_FIRST_SPLASH_ACTIVE);
            if (std::holds_alternative<bool>(val) and std::get<bool>(val)) {
                fmt::println("Pressing w, is splash active: {}", std::get<bool>(val));
                emit(SWITCH_TO_NEXT_SCENE);
            }
            wKeyPressed = true;
            break;
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
        case sf::Keyboard::W: {
            wKeyPressed = false;
            break;
        }
        default: {
        }
    }
}

auto Player::getBoundingBox() -> sf::FloatRect {
    return sf::FloatRect{pos, sf::Vector2f(40, 80)};
}

auto Player::renderBacklight(sf::Vector2f const& screenPos, sf::RenderWindow *window) -> void {
    backlight.setPosition(screenPos - sf::Vector2f(40, 80));
    window->draw(backlight);
}


auto Player::render(Context ctx) -> void {
    setAnimationState();
    auto texture = animatedTxt.getTexture();
    sprite.setTexture(*texture);
    float sign = vel.x > 0 || vec::isNearZero(vel.x) ? 1 : -1;
    sprite.setScale((float) 0.068 * sign, (float) 0.068 * sign);
    auto size = vec::toFloat(sprite.getTexture()->getSize());

    auto screenPos = ctx.globalPos + pos;

    renderBacklight(screenPos, ctx.window);

    if (sign < 0) {
        screenPos = screenPos + sf::Vector2f(40, 80);
        //Source: https://en.sfml-dev.org/forums/index.php?topic=10119.0
        sprite.setTextureRect(sf::IntRect(0, (int) size.y, (int) size.x, (int) -size.y));
    } else {
        sprite.setTextureRect(sf::IntRect(0, 0, (int) size.x, (int) size.y));
    }

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
        vel.x = (float) (horizontalMovement * 0.2);
    } else {
        auto finalVel = (double) vel.x;
        auto sign = vel.x > 0 ? 1 : -1;
        auto xSpeed = std::abs(vel.x == 0 ? 0.1 : vel.x) * 140;
        auto multiplier = 0.0004 * (1 / xSpeed);
        finalVel += horizontalMovement * multiplier;

        if (horizontalMovement == 0) {
            finalVel -= sign * 0.00001; // air friction
        }

        vel.x = (float) std::clamp(finalVel, -.2, .2);
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

auto Player::setAnimationState() -> void {
    if (vec::isNearZero(vel.x)) {
        animatedTxt.setSequence(std::vector<TextureId>{PLAYER_STILL});
    } else {
        animatedTxt.setSequence(std::vector<TextureId>{
            PLAYER_RUNNING_4,
            PLAYER_RUNNING_5,
            PLAYER_RUNNING_6,
            PLAYER_RUNNING_7,
            PLAYER_RUNNING_8,
            PLAYER_RUNNING_9,
            PLAYER_RUNNING_10,
            PLAYER_RUNNING_11,
        });
    }
}

auto Player::isWKeyPressed() -> bool {
    return wKeyPressed;
}

