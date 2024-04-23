
#pragma once

#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "../Context/Context.h"
#include "../PhysicalObject/PhysicsModule.h"

enum Layer {
    FOREGROUND,
    BACKGROUND,
};

class Object {
protected:
    explicit Object(const PhysicsModule *physicsModule, Layer layer = FOREGROUND);

    sf::Vector2f pos;
    sf::Vector2f vel;
    Layer layer;
    float zDistance{};
public:
    PhysicsModule physicsModule;

    auto getPos() -> sf::Vector2f;
    auto setPos(sf::Vector2f p) -> void;
    auto move(sf::Vector2f delta) -> void;

    auto getVel() -> sf::Vector2f;
    auto setVel(sf::Vector2f v) -> void;
    auto setVelX(float x) -> void;
    auto setVelY(float y) -> void;

    auto getLayer() -> Layer;
    virtual auto render(Context ctx) -> void = 0;
    virtual auto getBoundingBox() -> sf::Rect<float> = 0;
};

