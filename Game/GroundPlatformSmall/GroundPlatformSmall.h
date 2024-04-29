

#ifndef PJC_PROJECT_GROUNDPLATFORMSMALL_H
#define PJC_PROJECT_GROUNDPLATFORMSMALL_H
#include <SFML/Graphics.hpp>
#include "../../Engine/Object/Object.h"
#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../../Engine/TextureLoader/TextureLoader.h"
#include "../InitContext/InitContext.h"

class GroundPlatformSmall : public TexturedRect {
public:
    explicit GroundPlatformSmall(TextureLoader<TextureId> const& loader);
};


#endif //PJC_PROJECT_GROUNDPLATFORMSMALL_H
