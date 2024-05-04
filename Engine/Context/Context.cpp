#include "Context.h"

Context::Context(sf::RenderWindow &window, sf::Font &font): window(&window), font(&font) {
    globalPos = sf::Vector2f(0, 0);
}
