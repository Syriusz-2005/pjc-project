#include "Context.h"

Context::Context(sf::RenderWindow& window): window(&window) {
    globalPos = sf::Vector2f(0, 0);
}
