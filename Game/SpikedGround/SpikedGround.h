//
// Created by NOWY on 29.04.2024.
//

#ifndef PJC_PROJECT_SPIKEDGROUND_H
#define PJC_PROJECT_SPIKEDGROUND_H


#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../InitContext/InitContext.h"

class SpikedGround: public TexturedRect {
public:
    explicit SpikedGround(TextureLoader<TextureId> const& loader, std::string uid);

    bool onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) override;
};


#endif //PJC_PROJECT_SPIKEDGROUND_H
