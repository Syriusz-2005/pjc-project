

#include "VecUtils.h"

auto vec::length(sf::Vector2f &vec) -> float  {
    return vec.x + vec.y;
}

auto vec::multiply(sf::Vector2f &vec, float s) -> sf::Vector2f {
    return sf::Vector2f{vec.x * s, vec.y * s};
}

auto vec::divide(sf::Vector2u &v1, sf::Vector2u v2) -> sf::Vector2f {
    return sf::Vector2f{(float) v1.x / (float) v2.x, (float) v2.y / (float) v2.y};
}