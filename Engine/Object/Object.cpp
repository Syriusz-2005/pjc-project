#include <fmt/core.h>
#include <SFML/Graphics.hpp>

#include "Object.h"

Object::Object(PhysicsModule *physicsModule, Layer layer) : layer(layer), physicsModule(*physicsModule) {

}


auto Object::getPos() -> sf::Vector2f {
    return pos;
}

auto Object::getVel() -> sf::Vector2f {
    return vel;
}

auto Object::getLayer() -> Layer {
    return layer;
}

auto Object::setVel(sf::Vector2f v) -> void {
    this->vel = v;
}

auto Object::setPos(sf::Vector2f p) -> void {
    this->pos = p;
}

auto Object::move(sf::Vector2f delta) -> void {
    this->pos += delta;
}

auto Object::setVelX(float x) -> void {
    vel.x = x;
}

auto Object::setVelY(float y) -> void {
    vel.y = y;
}
