
#include "Tree.h"

Tree::Tree(): Object(PhysicsModule(0, 0, 0), BACKGROUND) {
    name = "tree";
    txt.loadFromFile("../assets/tree.png");
    sprite = sf::Sprite(txt);
    pos = sf::Vector2f(200, -400);
    zDistance = 2;
}

void Tree::render(Context ctx) {
    auto globalPos = pos + ctx.globalPos + sf::Vector2f(0,  zDistance * 300);
    sprite.setPosition(globalPos);
    sprite.setScale(1 / zDistance, 1 / zDistance);
    auto s = ctx.backgroundShader->getShader();
    s->setUniform("zDistance", zDistance);
    ctx.window->draw(sprite, s);
}

sf::Rect<float> Tree::getBoundingBox() {
    return sf::Rect<float>{0, 0, 0, 0};
}
