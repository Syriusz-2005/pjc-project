
#include "Scene.h"

#include "../VecUtils/VecUtils.h"


Scene::Scene(sf::Color clearColor, std::string uid): clearColor(clearColor), physicsEngine(PhysicsEngine(objects)), uid(uid) {

}

auto Scene::render(Context ctx) -> void {
    ctx.window->clear(clearColor);
    sf::Vector2u windowSize = ctx.window->getSize();
    auto windowSizeF = sf::Vector2f((float) windowSize.x, (float) windowSize.y);
    switch (backgroundSource) {
        case TEXTURE: {
            auto s = sf::Sprite(background);
            sf::Vector2u txtSize = background.getSize();
            auto finalBackgroundScale = vec::divide(windowSize, txtSize);
            s.setScale(finalBackgroundScale);
            ctx.window->draw(s);
        }
        case SHADER: {
            auto rect = sf::RectangleShape(windowSizeF);
            backgroundShader.setUniform("screenSize", windowSizeF);
            backgroundShader.setUniform("position", ctx.globalPos);
            ctx.window->draw(rect, &backgroundShader);
        }
        default: {}
    }

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

auto Scene::getBackgroundShader() -> sf::Shader & {
    return backgroundShader;
}

auto Scene::setBackgroundSource(BackgroundSource source) -> void {
    backgroundSource = source;
}

Scene::~Scene() {
    fmt::println("Disposing scene");
}

void Scene::load(nlohmann::json const& json) {
    for (auto objectData : json["objects"]) {
        auto objectId = objectData["uid"].get<std::string>();
        for (const auto& o : objects) {
            if (o->isUidMatch(objectId)) {
                o->load(objectData);
            }
        }
    }
}

std::unique_ptr<nlohmann::json> Scene::save() {
    auto json = std::make_unique<nlohmann::json>();
    (*json)["uid"] = uid;
    for (const auto& o : objects) {
        auto val = o->save();
        (*json)["objects"].push_back(*val);
    }
    return json;
}

bool Scene::isUidMatch(std::string &id) {
    return uid == id;
}
