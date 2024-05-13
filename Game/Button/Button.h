
#ifndef PJC_PROJECT_BUTTON_H
#define PJC_PROJECT_BUTTON_H


#include "../../Engine/Object/Object.h"

class Button : public Object {
    std::string text;
    sf::RectangleShape box{sf::Vector2f{400, 70}};
public:
    explicit Button(const std::string &uid,
                    const std::string &text);

    void render(Context ctx) override;
    sf::Rect<float> getBoundingBox() override;
    auto setText(std::string txt) -> void;
};


#endif //PJC_PROJECT_BUTTON_H
