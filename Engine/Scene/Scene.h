

#ifndef PJC_PROJECT_SCENE_H
#define PJC_PROJECT_SCENE_H

#include <vector>
#include "../Object/Object.h"
#include "../PhysicsEngine/PhysicsEngine.h"
#include "../BackgroundSource/BackgroundSource.h"
#include "../CompositeParent/CompositeParent.h"
#include <algorithm>


class Scene : public Savable, public CompositeParent<Object, int> {
private:
    std::vector<std::shared_ptr<Object>> objects = std::vector<std::shared_ptr<Object>>();
    sf::Color clearColor;
    PhysicsEngine physicsEngine;
    sf::Texture background{};
    sf::Shader backgroundShader{};
    BackgroundSource backgroundSource = COLOR;
    std::string uid;
    sf::Vector2f spawn;
    sf::RectangleShape backgroundShaderRect{};

public:
    explicit Scene(sf::Color clearColor, std::string uid, sf::Vector2f const& spawn);
    auto add(std::shared_ptr<Object> o) -> void override {
        o->setParent(this);
        objects.push_back(o);
    }
    void remove(std::shared_ptr<Object> o) override {
        const auto [first, last] = std::ranges::remove(objects.begin(), objects.end(), o);
        objects.erase(first, last);
    }
    void remove(std::string const& uid) override {
        const auto [first, last] = std::ranges::remove_if(objects, [uid](std::shared_ptr<Object>& val) -> bool {
            return val->isUidMatch(uid);
        });
        objects.erase(first, last);
    }
    auto getUid() -> std::string const&;
    const std::vector<std::shared_ptr<Object>>& getChildren(std::function<bool(Object&)> const& predicate) override;
    const std::vector<std::shared_ptr<Object>>& getChildren() override;
    auto render(Context ctx) -> void;
    auto getPhysicsEngine() -> PhysicsEngine const&;
    auto setBackground(std::string textureFile) -> void;

    auto setBackgroundSource(BackgroundSource source) -> void;

    auto getBackgroundShader() -> sf::Shader&;

    void load(nlohmann::json const& json) override;
    std::unique_ptr<nlohmann::json> save() override;
    bool isUidMatch(std::string const &id) const override;

    auto getSpawn() -> sf::Vector2f const&;

    ~Scene();
};


#endif //PJC_PROJECT_SCENE_H
