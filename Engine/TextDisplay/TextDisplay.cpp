

#include "TextDisplay.h"

TextDisplay::TextDisplay(const std::string &uid, const std::string &text): Object(PhysicsModule(0, 0, 0), uid, BACKGROUND), text(text) {

}

void TextDisplay::render(Context ctx) {
    auto drawableText = sf::Text(text, *ctx.font, 44);

    auto screenPos = ctx.globalPos + pos;
    drawableText.setFillColor(sf::Color::Black);
    drawableText.setPosition(screenPos);
    ctx.window->draw(drawableText);
}

sf::FloatRect TextDisplay::getBoundingBox() {
    return sf::FloatRect{pos, sf::Vector2f(0, 0)};
}
