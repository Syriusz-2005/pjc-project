#include "Rect.h"

Rect::Rect(PhysicsModule const& physicsModule, std::string uid, const sf::Vector2f size, Layer layer, sf::Color color) : Object(physicsModule, uid, layer), s(size) {
    s.setFillColor(color);
}

auto Rect::render(Context ctx) -> void {
    auto globalPos = pos + ctx.globalPos;
    s.setPosition(globalPos);
    ctx.window->draw(s);
}

auto Rect::getBoundingBox() -> sf::Rect<float> {
    auto box = sf::Rect<float>(pos, s.getSize());
    return box;
}
