
#ifndef PJC_PROJECT_TEXTUREDRECT_H
#define PJC_PROJECT_TEXTUREDRECT_H


#include "../Object/Object.h"
#include "../VecUtils/VecUtils.h"

class TexturedRect : public Object {
private:
    sf::Vector2f shift;

protected:
    sf::Sprite sprite;

    sf::Vector2f boxSize;
public:
    explicit TexturedRect(
            PhysicsModule const& physicsModule,
            std::string uid,
            sf::Texture const& txt,
            sf::Vector2f const& shift,
            Layer const& layer = FOREGROUND
    );

    auto render(Context ctx) -> void override;
    auto getBoundingBox() -> sf::Rect<float> override;
};


#endif //PJC_PROJECT_TEXTUREDRECT_H
