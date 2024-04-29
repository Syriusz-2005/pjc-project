

#ifndef PJC_PROJECT_GROUND_H
#define PJC_PROJECT_GROUND_H
#include <SFML/Graphics.hpp>
#include "../../Engine/Object/Object.h"
#include "../../Engine/TexturedRect/TexturedRect.h"


class Ground : public TexturedRect {
public:
    explicit Ground(sf::Texture const& txt, sf::Vector2f const& shift);
};


#endif //PJC_PROJECT_GROUND_H
