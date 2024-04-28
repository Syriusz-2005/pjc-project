
#ifndef PJC_PROJECT_INITCONTEXT_H
#define PJC_PROJECT_INITCONTEXT_H


#include "../../Engine/TextureLoader/TextureLoader.h"

enum TextureId {
    TREE,
    GROUND,
    PLAYER_STILL,
};


struct InitContext {
    TextureLoader<TextureId> const* textureLoader;
};


#endif //PJC_PROJECT_INITCONTEXT_H
