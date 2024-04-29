
#ifndef PJC_PROJECT_PHYSICSMODULE_H
#define PJC_PROJECT_PHYSICSMODULE_H


#include "../Savable/Savable.h"

class PhysicsModule : public Savable {
public:
    float mass;
    float gravity;

    bool isImmovable = false;
    /**
     * Does it interact with other objects?
     */
    bool isEthereal = false;
    float bounciness = 1;

    bool isOnGround = false;

    explicit PhysicsModule(
            float mass = 1,
            float gravity = 0.0003,
            float bounciness = 1);

    void load(nlohmann::json const& json) override;
    std::unique_ptr<nlohmann::json> save() override;
    bool isUidMatch(std::string &id) override {return false;}
};


#endif //PJC_PROJECT_PHYSICSMODULE_H
