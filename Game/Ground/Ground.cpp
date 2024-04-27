//
// Created by NOWY on 27.04.2024.
//

#include "Ground.h"

Ground::Ground(): Object(PhysicsModule(), FOREGROUND) {
    name = "Ground";
    txt.loadFromFile("../assets/grass.png");
    sprite = sf::Sprite(txt);
//    pos = sf::Vector2f(200, -400);
}

void Ground::render(Context ctx) {
    auto globalPos = pos + ctx.globalPos - sf::Vector2f(0, 190);
    sprite.setPosition(globalPos);
    ctx.window->draw(sprite);
}

sf::Rect<float> Ground::getBoundingBox() {
    return sf::Rect<float>{pos, sf::Vector2f{2600, 800}};
}
