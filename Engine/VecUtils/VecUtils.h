
#ifndef PJC_PROJECT_VECUTILS_H
#define PJC_PROJECT_VECUTILS_H


#include <SFML/Graphics.hpp>

 namespace vec {
    auto toFloat(sf::Vector2u const& vec) -> sf::Vector2f;
    auto length(sf::Vector2f const& vec) -> float;
    auto multiply(sf::Vector2f const& vec, float s) -> sf::Vector2f;
    auto divide(sf::Vector2u const& v1, sf::Vector2u const& v2) -> sf::Vector2f;
    auto divide(sf::Vector2f const& v1, float s) -> sf::Vector2f;
    auto mix(sf::Vector2f const& v1, sf::Vector2f const& v2, float t) -> sf::Vector2f;
    auto distance(sf::Vector2f const& v1, sf::Vector2f const& v2) -> float;

    auto isNearZero(float a) -> bool;
    auto isNearZero(sf::Vector2f a) -> bool;
}

#endif //PJC_PROJECT_VECUTILS_H
