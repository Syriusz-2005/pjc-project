#include <SFML/Graphics.hpp>
#include "Camera.h"

auto Camera::getPos() -> sf::Vector2f {
    return pos;
}

auto Camera::setPos(sf::Vector2f newPos) -> void {
    pos = newPos;
}


