

#ifndef PJC_PROJECT_GROUND_H
#define PJC_PROJECT_GROUND_H
#include <SFML/Graphics.hpp>
#include "../../Engine/Object/Object.h"


class Ground : public Object {
    sf::Texture txt = sf::Texture();
    sf::Sprite sprite;

public:
    Ground();

    void render(Context ctx) override;
    sf::Rect<float> getBoundingBox() override;
};


#endif //PJC_PROJECT_GROUND_H
