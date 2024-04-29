//
// Created by NOWY on 29.04.2024.
//

#ifndef PJC_PROJECT_SPIKEDGROUND_H
#define PJC_PROJECT_SPIKEDGROUND_H


#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../InitContext/InitContext.h"

class SpikedGround: public TexturedRect {
public:
    explicit SpikedGround(TextureLoader<TextureId> const& loader);
};


#endif //PJC_PROJECT_SPIKEDGROUND_H
