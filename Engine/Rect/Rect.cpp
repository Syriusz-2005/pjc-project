#include "Rect.h"

Rect::Rect(PhysicalObject& physicsModule, const sf::Vector2f size, Layer layer, sf::Color color) : Object(&physicsModule, layer), s(size) {
    s.setFillColor(color);
}

auto Rect::render(Context ctx) -> void {
    auto globalPos = pos + ctx.globalPos;
    s.setPosition(globalPos);
    ctx.window->draw(s);
}
