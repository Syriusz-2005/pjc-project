#include <fmt/core.h>
#include <SFML/Graphics.hpp>

#include "Object.h"

Object::Object(PhysicsModule const& physicsModule, std::string uid, Layer layer) : layer(layer), physicsModule(physicsModule), uid(uid) {

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

Object::~Object() {
    fmt::println("{}: Destroyed", name);
}

auto Object::getZDistance() const -> float {
    return zDistance;
}

auto Object::load(nlohmann::json const& json) -> void {
    // Probably could've serialised the whole object right?
    pos.x = json["pos"]["x"];
    pos.y = json["pos"]["y"];
    vel.x = json["vel"]["x"];
    vel.y = json["vel"]["y"];
    layer = json["layer"];
    zDistance = json["zDistance"];
    name = json["name"];
    physicsModule.load(json["physicsModule"]);
}

auto Object::save() -> std::unique_ptr<nlohmann::json> {
    auto json = std::make_unique<nlohmann::json>();
    (*json)["physicsModule"] = *physicsModule.save();
    (*json)["pos"]["x"] = pos.x;
    (*json)["pos"]["y"] = pos.y;
    (*json)["vel"]["x"] = vel.x;
    (*json)["vel"]["y"] = vel.y;
    (*json)["layer"] = layer;
    (*json)["zDistance"] = zDistance;
    (*json)["name"] = name;
    (*json)["uid"] = uid;
    return json;
}

bool Object::isUidMatch(std::string& id) {
    return id == uid;
}
