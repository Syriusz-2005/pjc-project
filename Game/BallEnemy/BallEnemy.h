
#ifndef PJC_PROJECT_BALLENEMY_H
#define PJC_PROJECT_BALLENEMY_H

#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../InitContext/InitContext.h"
#include "../../Engine/MortalEntityModule/MortalEntityModule.h"

class BallEnemy : public TexturedRect {
private:
    std::function<void()> onDeath = [this]() -> void {
        fmt::println("Trying to remove ball...");
        parent->remove(getUid());
        fmt::println("Ball removed");
    };
    std::shared_ptr<EntityModule> entityModule = std::make_shared<MortalEntityModule>(10, onDeath);
public:
    BallEnemy(TextureLoader<TextureId> const& loader, std::string const& uid);

    bool onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) override;
    void onAfterStep() override;
};


#endif //PJC_PROJECT_BALLENEMY_H
