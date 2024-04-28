
#include "Scene.h"

#include "../VecUtils/VecUtils.h"


Scene::Scene(sf::Color clearColor): clearColor(clearColor), physicsEngine(PhysicsEngine(objects)) {

}

auto Scene::render(Context ctx) -> void {
    ctx.window->clear(clearColor);

    auto s = sf::Sprite(background);
//    s.setPosition(ctx.globalPos.x, ctx.globalPos.y);
    sf::Vector2u txtSize = background.getSize();
    sf::Vector2u windowSize = ctx.window->getSize();
    auto finalBackgroundScale = vec::divide(windowSize, txtSize);
    s.setScale(finalBackgroundScale);
    ctx.window->draw(s);

    for (const auto& object : objects) {
        object->render(ctx);
    }
}


auto Scene::getObjects() -> std::vector<std::shared_ptr<Object>>& {
    return objects;
}

auto Scene::getPhysicsEngine() -> PhysicsEngine const & {
    return physicsEngine;
}

auto Scene::setBackground(std::string textureFile) -> void {
    background.loadFromFile(textureFile);
}
