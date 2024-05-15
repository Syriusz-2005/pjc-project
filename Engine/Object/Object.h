
#pragma once

#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include "../Context/Context.h"
#include "../PhysicalObject/PhysicsModule.h"
#include "../Savable/Savable.h"
#include "../EntityModule/EntityModule.h"
#include "../CompositeParent/CompositeParent.h"
#include "../../Game/ObjectType/ObjectType.h"


enum Layer {
    FOREGROUND,
    BACKGROUND,
};


class Object : public Savable {
private:
    std::string uid;
    std::shared_ptr<EntityModule> entityModule;
    int type;

protected:
    explicit Object(
            PhysicsModule const &physicsModule,
            std::string uid, Layer layer = FOREGROUND
    );

    auto setEntityModule(std::shared_ptr<EntityModule>& module) -> void;
    auto setType(int t) -> void;

    sf::Vector2f pos;
    sf::Vector2f vel;
    Layer layer;
    float zDistance{};

    CompositeParent<Object, int>* parent;
public:
    auto getUid() -> std::string const&;
    PhysicsModule physicsModule;
    std::string name;
    bool isVisible{true};

    auto getType() -> int;

    auto setParent(CompositeParent<Object, int>* p) -> void;

    auto getPos() -> sf::Vector2f;

    auto setPos(sf::Vector2f p) -> void;
    auto setPos(float x, float y) -> void;

    auto move(sf::Vector2f delta) -> void;

    auto getVel() -> sf::Vector2f;

    auto setVel(sf::Vector2f v) -> void;

    auto setVelX(float x) -> void;

    auto setVelY(float y) -> void;

    [[nodiscard]] auto getZDistance() const -> float;

    auto getLayer() -> Layer;

    virtual auto render(Context ctx) -> void = 0;

    virtual auto getBoundingBox() -> sf::Rect<float> = 0;

    virtual auto onAfterStep() -> void {}

    virtual auto onBeforeStep(long long timeElapsed) -> void {}

    virtual auto onBeforeCollision(std::shared_ptr<Object> const &collisionTarget) -> bool { return true; }
    virtual auto onAfterCollision(std::shared_ptr<Object> const& collisionTarget) -> void {};

    virtual auto applyDamage(float damageValue) -> void;

    auto load(nlohmann::json const &json) -> void override;

    auto save() -> std::unique_ptr<nlohmann::json> override;

    bool isUidMatch(std::string const& id) const override;
    auto isTheSame(Object const* o) const -> bool;

    virtual ~Object();
};

