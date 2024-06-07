
#include <random>
#include "VecUtils.h"

auto vec::toFloat(sf::Vector2u const& vec) -> sf::Vector2f {
    return sf::Vector2f{(float) vec.x, (float) vec.y};
}

auto vec::length(sf::Vector2f const&vec) -> float  {
    return (float) std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
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

auto vec::rand(sf::Vector2f const& from, sf::Vector2f const& to) -> sf::Vector2f {
    auto d = to - from;
    auto middle = from + vec::divide(d, 2);
    //Source: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
    std::random_device dev;
    std::mt19937 rng(dev());
    std::normal_distribution<double> distX(middle.x,d.x / 2);
    std::normal_distribution<double> distY(middle.y,d.y / 2);
    auto resX = distX(rng);
    auto resY = distY(rng);
    return sf::Vector2f{(float) resX, (float) resY};
}

auto vec::rand(sf::Vector2f const& middle, float manhattanDistance) -> sf::Vector2f {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::normal_distribution<double> distX(middle.x, manhattanDistance);
    std::normal_distribution<double> distY(middle.y, manhattanDistance);
    auto resX = distX(rng);
    auto resY = distY(rng);
    return sf::Vector2f{(float) resX, (float) resY};
}

auto vec::normalize(sf::Vector2f const& v) -> sf::Vector2f {
    return vec::divide(v, vec::length(v));
}

auto vec::isNearZero(float a) -> bool {
    return std::abs(a) < 0.0001;
}
auto vec::isNearZero(sf::Vector2f a) -> bool {
    return isNearZero(length(a));
}