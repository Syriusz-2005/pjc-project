
#ifndef PJC_PROJECT_FLY_H
#define PJC_PROJECT_FLY_H


#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../InitContext/InitContext.h"

class Fly : public TexturedRect {
    sf::Vector2f spawnPos{};
    // A separate Pathfinding module would be nicer
    sf::Vector2f pathTarget{};
    int shootDelayMs{3000};
    int lastProjectileIndex{0};

    auto setNewTarget() -> void;

public:
    explicit Fly(
            TextureLoader<TextureId> const& loader,
            std::string const& uid);

    void onBeforeStep(long long timeElapsed) override;
};


#endif //PJC_PROJECT_FLY_H
