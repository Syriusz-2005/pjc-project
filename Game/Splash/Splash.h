

#ifndef PJC_PROJECT_SPLASH_H
#define PJC_PROJECT_SPLASH_H


#include "../../Engine/Object/Object.h"

class Splash : public Object {
    sf::RectangleShape shape{sf::Vector2f(512, 512)};
public:
    explicit Splash(std::string const& uid);

    void render(Context ctx) override;
    sf::FloatRect getBoundingBox() override;
};


#endif //PJC_PROJECT_SPLASH_H
