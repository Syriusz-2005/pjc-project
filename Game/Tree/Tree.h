//
// Created by NOWY on 27.04.2024.
//

#ifndef PJC_PROJECT_TREE_H
#define PJC_PROJECT_TREE_H


#include "../../Engine/Object/Object.h"
#include <SFML/Graphics.hpp>

class Tree : public Object {
    sf::Texture txt = sf::Texture();
    sf::Sprite sprite;

public:
    Tree(float posX);

    void render(Context ctx) override;
    sf::Rect<float> getBoundingBox() override;
};


#endif //PJC_PROJECT_TREE_H
