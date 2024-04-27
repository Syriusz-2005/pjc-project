
#ifndef PJC_PROJECT_VECUTILS_H
#define PJC_PROJECT_VECUTILS_H

#include <SFML/Graphics.hpp>
 namespace vec {
    auto length(sf::Vector2f& vec) -> float {
        return vec.x + vec.y;
    }
    auto multiply(sf::Vector2f& vec, float s) -> sf::Vector2f {
        return sf::Vector2f{vec.x * s, vec.y * s};
    }
}

#endif //PJC_PROJECT_VECUTILS_H
