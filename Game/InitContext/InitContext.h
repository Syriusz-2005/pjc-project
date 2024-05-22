
#ifndef PJC_PROJECT_INITCONTEXT_H
#define PJC_PROJECT_INITCONTEXT_H


#include <memory>
#include "../../Engine/TextureLoader/TextureLoader.h"
#include "../../Engine/Camera/Camera.h"

enum TextureId {
    TREE,
    GROUND,
    GROUND_PLATFORM_SMALL,

    PLAYER_STILL,
    SPIKES_GROUND,

    ENEMY_BALL,

    PLAYER_RUNNING_4,
    PLAYER_RUNNING_5,
    PLAYER_RUNNING_6,
    PLAYER_RUNNING_7,
    PLAYER_RUNNING_8,
    PLAYER_RUNNING_9,
    PLAYER_RUNNING_10,
    PLAYER_RUNNING_11,

    BACKLIGHT,
    GAME_TITLE,
    ABILITY,
};


struct InitContext {
    TextureLoader<TextureId> const* textureLoader;
    sf::RenderWindow const& window;
    Camera const& camera;
    std::unique_ptr<std::vector<std::string>> const& saveNames;
};


#endif //PJC_PROJECT_INITCONTEXT_H
