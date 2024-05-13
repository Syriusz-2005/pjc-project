
#include "Button.h"

#include <utility>
#include "../../Engine/VecUtils/VecUtils.h"

Button::Button(const std::string &uid,
               const std::string &text) : Object(PhysicsModule(0, 0, 0, true), uid, BACKGROUND), text(text) {

    setType(BUTTON);
    box.setFillColor(sf::Color{0, 0, 0});
}

void Button::render(Context ctx) {
    auto screenPos = ctx.globalPos + pos;
    box.setPosition(screenPos);
    ctx.window->draw(box);
    auto drawableText = sf::Text{text, *ctx.font, 30};
    drawableText.setFillColor(sf::Color(255, 255, 255));
    auto bounds = drawableText.getGlobalBounds();
    drawableText.setPosition(screenPos + vec::divide(box.getSize() - sf::Vector2f{bounds.width, bounds.height}, 2) - sf::Vector2f{0, 10});
    ctx.window->draw(drawableText);
}

sf::Rect<float> Button::getBoundingBox() {
    return sf::FloatRect{pos, box.getSize()};
}

auto Button::setText(std::string txt) -> void {
    text = std::move(txt);
}
