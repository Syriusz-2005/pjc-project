#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "../Context/Context.h"

#pragma once

enum Layer {
    FOREGROUND,
    BACKGROUND,
};

class Object {
protected:
    explicit Object(Layer layer);

    sf::Vector2f pos;
    sf::Vector2f vel;
    Layer layer;
    float zDistance{};
public:
    auto getPos() -> sf::Vector2f;
    auto getVel() -> sf::Vector2f;
    virtual auto render(Context ctx) -> void = 0;
};

