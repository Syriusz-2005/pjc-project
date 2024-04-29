
#ifndef PJC_PROJECT_TREE_H
#define PJC_PROJECT_TREE_H


#include "../../Engine/Object/Object.h"
#include "../InitContext/InitContext.h"
#include <SFML/Graphics.hpp>

class Tree : public Object {
    sf::Sprite sprite;
    sf::Texture const* txt;

public:
    Tree(float posX, std::string uid, InitContext const& ctx);

    void render(Context ctx) override;
    sf::Rect<float> getBoundingBox() override;
};


#endif //PJC_PROJECT_TREE_H
