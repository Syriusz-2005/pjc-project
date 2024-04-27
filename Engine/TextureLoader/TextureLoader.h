
#ifndef PJC_PROJECT_TEXTURELOADER_H
#define PJC_PROJECT_TEXTURELOADER_H

#include <map>
#include <SFML/Graphics.hpp>


template <typename T>
class TextureLoader {
    std::map<T, sf::Texture const*> atlas = std::map<T, sf::Texture const*>{};
public:
    explicit TextureLoader() = default;

    auto registerTexture(T id, std::string const& pathToFile) -> void {
        auto newTexture = new sf::Texture();
        newTexture->loadFromFile(pathToFile);
        atlas[id] = newTexture;
    }

    auto getTexture(T id) const -> sf::Texture const* {
        return atlas.at(id);
    };

    ~TextureLoader() {
        for (auto [_, texture] : atlas) {
            delete texture;
        }
    }
};


#endif //PJC_PROJECT_TEXTURELOADER_H
