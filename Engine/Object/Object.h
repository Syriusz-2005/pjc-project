
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
    explicit Object(PhysicsModule const& physicsModule, Layer layer = FOREGROUND);

    sf::Vector2f pos;
    sf::Vector2f vel;
    Layer layer;
    float zDistance{};
public:
    PhysicsModule physicsModule;
    std::string name;

    auto getPos() -> sf::Vector2f;
    auto setPos(sf::Vector2f p) -> void;
    auto move(sf::Vector2f delta) -> void;

    auto getVel() -> sf::Vector2f;
    auto setVel(sf::Vector2f v) -> void;
    auto setVelX(float x) -> void;
    auto setVelY(float y) -> void;
    auto getZDistance() const -> float;

    auto getLayer() -> Layer;
    virtual auto render(Context ctx) -> void = 0;
    virtual auto getBoundingBox() -> sf::Rect<float> = 0;
    virtual auto onAfterStep() -> void {}
    virtual auto onBeforeStep() -> void {}

    virtual ~Object();
};

