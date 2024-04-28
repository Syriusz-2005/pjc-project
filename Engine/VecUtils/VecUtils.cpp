

#include "VecUtils.h"

auto vec::toFloat(sf::Vector2u const& vec) -> sf::Vector2f {
    return sf::Vector2f((float) vec.x, (float) vec.y);
}

auto vec::length(sf::Vector2f const&vec) -> float  {
    return vec.x + vec.y;
}

auto vec::multiply(sf::Vector2f const&vec, float s) -> sf::Vector2f {
    return sf::Vector2f{vec.x * s, vec.y * s};
}

auto vec::divide(sf::Vector2u const&v1, sf::Vector2u const& v2) -> sf::Vector2f {
    return sf::Vector2f{(float) v1.x / (float) v2.x, (float) v2.y / (float) v2.y};
}