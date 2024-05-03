

#ifndef PJC_PROJECT_TEXTURESWITCHER_H
#define PJC_PROJECT_TEXTURESWITCHER_H


#include "../TextureLoader/TextureLoader.h"
#include "fmt/core.h"

template <typename T>
class TextureSwitcher {
    int switchDelta;
    int textureIndex{0};

    sf::Clock time{};
    std::vector<T> currentSequence{};
    TextureLoader<T> const& loader;

public:
    /**
     *
     * @param loader
     * @param textureIds
     * @param switchDelta Time in milliseconds
     */
    explicit TextureSwitcher(TextureLoader<T> const& loader, std::vector<T> const& textureIds, int switchDelta)
        : switchDelta(switchDelta),
        loader(loader) {
        currentSequence = textureIds;
    }

    auto setSequence(std::vector<T> const& seq) -> void {
        if (currentSequence == seq) {
            return;
        }
        time.restart();
        textureIndex = 0;
        currentSequence = seq;
    }

    auto getTexture() -> sf::Texture const* {
        auto delta = time.getElapsedTime().asMilliseconds();

        if (delta >= switchDelta) {
            time.restart();
            textureIndex++;
        }

        auto currentTextureId = currentSequence[textureIndex % currentSequence.size()];
        return loader.getTexture(currentTextureId);
    }
};


#endif //PJC_PROJECT_TEXTURESWITCHER_H
