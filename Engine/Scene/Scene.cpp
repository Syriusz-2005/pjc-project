
#include "Scene.h"

#include "../VecUtils/VecUtils.h"


Scene::Scene(sf::Color clearColor, std::string uid, sf::Vector2f const& spawn):
clearColor(clearColor),
physicsEngine(PhysicsEngine(objects)),
uid(uid),
spawn(spawn) {

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
            backgroundShaderRect.setSize(windowSizeF);
            backgroundShader.setUniform("screenSize", windowSizeF);
            backgroundShader.setUniform("position", ctx.globalPos);
            ctx.window->draw(backgroundShaderRect, &backgroundShader);
        }
        default: {}
    }


    for (const auto& object : objects) {
        object->render(ctx);
    }
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
        if (o->isSavable) {
            auto val = o->save();
            (*json)["objects"].push_back(*val);
        }
    }
    return json;
}

bool Scene::isUidMatch(std::string const&id) const {
    return uid == id;
}

const std::vector<std::shared_ptr<Object>> &Scene::getChildren() {
    return objects;
}

const std::vector<std::shared_ptr<Object>> &Scene::getChildren(std::function<bool(Object&)> const& predicate) {
    auto filteredObjects = new std::vector<std::shared_ptr<Object>>{};
    for (auto& object : objects) {
        if (predicate(*object)) {
            filteredObjects->push_back(object);
        }
    }
    return *filteredObjects;
}

auto Scene::getSpawn() -> sf::Vector2f const & {
    return spawn;
}
