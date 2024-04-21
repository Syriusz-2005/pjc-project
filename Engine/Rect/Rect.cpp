#include "Rect.h"

Rect::Rect(const sf::Vector2f size, Layer layer, sf::Color color) : Object(layer), s(size) {
    s.setFillColor(color);
}

auto Rect::render(Context ctx) -> void {
    auto globalPos = pos + ctx.globalPos;
    s.setPosition(globalPos);
    ctx.window->draw(s);
}
