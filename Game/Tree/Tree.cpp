
#include "Tree.h"
#include <cmath>
#include "../../Engine/VecUtils/VecUtils.h"

Tree::Tree(float posX, std::string uid, InitContext const& ctx)
    : Object(PhysicsModule(0, 0, 0), uid, BACKGROUND) {
    name = "tree";
    txt = ctx.textureLoader->getTexture(TREE);
    sprite = sf::Sprite(*txt);
    std::srand((int) (posX * 2.8));
    auto s = txt->getSize();
    float distance = ((float) (std::rand() % 35)) / 10 + 1.1;
    pos = sf::Vector2f(posX, (float) -730);
    zDistance = distance;
    isSavable = false;
}

void Tree::render(Context ctx) {
    auto globalPos = pos + ctx.globalPos + sf::Vector2f(0,  zDistance * txt->getSize().y / 4);
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
