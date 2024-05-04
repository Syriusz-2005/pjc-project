#include "Splash.h"

Splash::Splash(std::string const &uid) : Object(PhysicsModule(0, 0, 0), uid, BACKGROUND) {
    name = "Splash teleport";
}

void Splash::render(Context ctx) {
    auto globalPos = pos + ctx.globalPos;

    auto shader = ctx.splashShader->getShader();
    shader->setUniform("size", shape.getSize());
    shape.setPosition(globalPos);
    ctx.window->draw(shape, shader);
}

sf::FloatRect Splash::getBoundingBox() {
    return sf::FloatRect{pos, shape.getSize()};
}
