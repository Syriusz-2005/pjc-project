

#ifndef PJC_PROJECT_SCENE_H
#define PJC_PROJECT_SCENE_H

#include <vector>
#include "../Object/Object.h"
#include "../PhysicsEngine/PhysicsEngine.h"
#include "../BackgroundSource/BackgroundSource.h"
#include "../CompositeParent/CompositeParent.h"


class Scene : public Savable, public CompositeParent<Object> {
private:
    std::vector<std::shared_ptr<Object>> objects = std::vector<std::shared_ptr<Object>>();
    sf::Color clearColor;
    PhysicsEngine physicsEngine;
    sf::Texture background{};
    sf::Shader backgroundShader{};
    BackgroundSource backgroundSource = COLOR;
    std::string uid;

public:
    explicit Scene(sf::Color clearColor, std::string uid);
    auto add(std::shared_ptr<Object> o) -> void override {
        o->setParent(this);
        objects.push_back(o);
    }
    void remove(std::shared_ptr<Object> o) override {
        std::ranges::remove(objects.begin(), objects.end(), o);
    }
    void remove(Object *o) override {
        std::ranges::remove_if(objects.begin(), objects.end(), [o](std::shared_ptr<Object>& val) -> bool {
            return val->isTheSame(o);
        });
    }
    auto render(Context ctx) -> void;
    auto getObjects() -> std::vector<std::shared_ptr<Object>>& ;
    auto getPhysicsEngine() -> PhysicsEngine const&;
    auto setBackground(std::string textureFile) -> void;

    auto setBackgroundSource(BackgroundSource source) -> void;

    auto getBackgroundShader() -> sf::Shader&;

    void load(nlohmann::json const& json) override;
    std::unique_ptr<nlohmann::json> save() override;
    bool isUidMatch(std::string const &id) const override;

    ~Scene();
};


#endif //PJC_PROJECT_SCENE_H
