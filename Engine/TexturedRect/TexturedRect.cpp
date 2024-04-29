
#include "TexturedRect.h"
#include "../VecUtils/VecUtils.h"

TexturedRect::TexturedRect(const PhysicsModule &physicsModule, std::string uid, sf::Texture const& txt, sf::Vector2f const& shift, Layer const& layer)
: Object(physicsModule, uid, layer), sprite(sf::Sprite(txt)), shift(shift){

}

auto TexturedRect::render(Context ctx) -> void {
    auto screenPos = ctx.globalPos + pos + shift;
    sprite.setPosition(screenPos);
    ctx.window->draw(sprite);
}

auto TexturedRect::getBoundingBox() -> sf::Rect<float> {
    return sf::FloatRect{pos, vec::toFloat(sprite.getTexture()->getSize())};
}
