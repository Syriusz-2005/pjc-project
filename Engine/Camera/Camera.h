#include <SFML/Graphics.hpp>

#ifndef PJC_PROJECT_CAMERA_H
#define PJC_PROJECT_CAMERA_H


class Camera {
private:
    sf::Vector2f pos;

public:
    auto getPos() const -> sf::Vector2f;
    auto setPos(sf::Vector2f newPos) -> void;
};

#endif //PJC_PROJECT_CAMERA_H
