

#ifndef PJC_PROJECT_SPLASH_H
#define PJC_PROJECT_SPLASH_H


#include "../../Engine/Object/Object.h"
#include "../../Engine/TextDisplay/TextDisplay.h"

class Splash : public Object {
    sf::RectangleShape shape{sf::Vector2f(512, 512)};
    TextDisplay info{"splash_text_display", "Press 'W' to enter"};
    bool displayInfo{false};
public:
    explicit Splash(std::string const& uid);

    void render(Context ctx) override;
    sf::FloatRect getBoundingBox() override;
    bool onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) override;
};


#endif //PJC_PROJECT_SPLASH_H
