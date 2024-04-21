#include <SFML/Graphics.hpp>

#pragma once

struct Context {
    sf::RenderWindow* window{};
    sf::Vector2f globalPos;

    explicit Context(sf::RenderWindow& window);
};