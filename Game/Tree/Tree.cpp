
#include "Tree.h"
#include <cmath>
#include "../../Engine/VecUtils/VecUtils.h"

Tree::Tree(float posX): Object(PhysicsModule(0, 0, 0), BACKGROUND) {
    name = "tree";
    txt.loadFromFile("../assets/tree.png");
    sprite = sf::Sprite(txt);
    std::srand((int) posX);
    auto s = txt.getSize();
    float distance = ((float) (std::rand() % 4)) + 1;
    pos = sf::Vector2f(posX, (float) -730);
    zDistance = distance;
}

void Tree::render(Context ctx) {
    auto globalPos = pos + ctx.globalPos + sf::Vector2f(0,  zDistance * txt.getSize().y / 4);
    globalPos = vec::multiply(globalPos, 1 / zDistance);
    sprite.setPosition(globalPos);
    sprite.setScale(1 / zDistance, 1 / zDistance);
    auto s = ctx.backgroundShader->getShader();
    s->setUniform("zDistance", zDistance);
    ctx.window->draw(sprite, s);
}

sf::Rect<float> Tree::getBoundingBox() {
    return sf::Rect<float>{0, 0, 0, 0};
}
