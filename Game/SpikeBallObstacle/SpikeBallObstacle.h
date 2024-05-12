
#ifndef PJC_PROJECT_SPIKEBALLOBSTACLE_H
#define PJC_PROJECT_SPIKEBALLOBSTACLE_H


#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../InitContext/InitContext.h"

class SpikeBallObstacle : public TexturedRect {
public:
    explicit SpikeBallObstacle(
            TextureLoader<TextureId> const& loader,
            std::string const& uid,
            PhysicsModule const& module = PhysicsModule(0, 0, 0, true));

    bool onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) override;
};


#endif //PJC_PROJECT_SPIKEBALLOBSTACLE_H
