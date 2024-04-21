#include <fmt/core.h>
#include <SFML/Graphics.hpp>

#include "Object.h"

Object::Object(Layer layer) : layer(layer) {

}


auto Object::getPos() -> sf::Vector2f {
    return pos;
}

auto Object::getVel() -> sf::Vector2f {
    return vel;
}

