
#ifndef PJC_PROJECT_INITCONTEXT_H
#define PJC_PROJECT_INITCONTEXT_H


#include "../../Engine/TextureLoader/TextureLoader.h"

enum TextureId {
    TREE,
    GROUND,
    GROUND_PLATFORM_SMALL,

    PLAYER_STILL,
    SPIKES_GROUND,

    ENEMY_BALL,
};


struct InitContext {
    TextureLoader<TextureId> const* textureLoader;
};


#endif //PJC_PROJECT_INITCONTEXT_H
