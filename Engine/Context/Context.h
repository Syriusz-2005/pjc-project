#include <SFML/Graphics.hpp>
#include "../../Game/BackgroundShader/BackgroundShader.h"
#include "../../Game/SplashShader/SplashShader.h"

#pragma once

struct Context {
    sf::RenderWindow * window;
    BackgroundShader * backgroundShader;
    SplashShader* splashShader;
    sf::Vector2f globalPos;

    explicit Context(sf::RenderWindow & window);
};