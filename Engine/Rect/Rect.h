
#ifndef PJC_PROJECT_RECT_H
#define PJC_PROJECT_RECT_H

#include "../Object/Object.h"
#include "../PhysicalObject/PhysicsModule.h"

class Rect : public Object {
protected:
    sf::RectangleShape s;

public:

    explicit Rect(
            PhysicsModule& physicsModule,
            sf::Vector2f size = sf::Vector2f(40, 40),
            Layer layer = FOREGROUND,
            sf::Color color = sf::Color(0, 0, 0)
    );

    auto render(Context ctx) -> void override;
    auto getBoundingBox() -> sf::Rect<float> override;
};


#endif //PJC_PROJECT_RECT_H
