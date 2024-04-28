
#ifndef PJC_PROJECT_VECUTILS_H
#define PJC_PROJECT_VECUTILS_H


#include <SFML/Graphics.hpp>

 namespace vec {
    auto length(sf::Vector2f& vec) -> float;
    auto multiply(sf::Vector2f& vec, float s) -> sf::Vector2f;
    auto divide(sf::Vector2u& v1, sf::Vector2u v2) -> sf::Vector2f;
}

#endif //PJC_PROJECT_VECUTILS_H
