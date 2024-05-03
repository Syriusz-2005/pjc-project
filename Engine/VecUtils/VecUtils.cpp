

#include "VecUtils.h"

auto vec::toFloat(sf::Vector2u const& vec) -> sf::Vector2f {
    return sf::Vector2f{(float) vec.x, (float) vec.y};
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

auto vec::divide(const sf::Vector2f &v1, float s) -> sf::Vector2f {
    return sf::Vector2f{v1.x / s, v1.y / s};
}

auto vec::mix(sf::Vector2f const& v1, sf::Vector2f const& v2, float t) -> sf::Vector2f {
    auto d = v2 - v1;
    return sf::Vector2f(v1) + d * t;
}

auto vec::distance(const sf::Vector2f &v1, const sf::Vector2f &v2) -> float {
    auto d = v1 - v2;
    return std::abs(d.x) + std::abs(d.y);
}

auto vec::isNearZero(float a) -> bool {
    return std::abs(a) < 0.0001;
}
auto vec::isNearZero(sf::Vector2f a) -> bool {
    return isNearZero(length(a));
}