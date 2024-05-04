#include <SFML/Graphics.hpp>
#include "../../Game/BackgroundShader/BackgroundShader.h"
#include "../../Game/SplashShader/SplashShader.h"

#pragma once

struct Context {
    sf::RenderWindow *window;
    BackgroundShader *backgroundShader;
    SplashShader *splashShader;
    sf::Font *font;
    sf::Vector2f globalPos;
    int frame;

    explicit Context(sf::RenderWindow &window, sf::Font &font);
};