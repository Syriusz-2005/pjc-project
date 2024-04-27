#include <SFML/Graphics.hpp>
#include "../../Game/BackgroundShader/BackgroundShader.h"

#pragma once

struct Context {
    sf::RenderWindow * window;
    BackgroundShader * backgroundShader;
    sf::Vector2f globalPos;

    explicit Context(sf::RenderWindow & window);
};