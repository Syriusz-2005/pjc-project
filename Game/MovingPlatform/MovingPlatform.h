
#ifndef PJC_PROJECT_MOVINGPLATFORM_H
#define PJC_PROJECT_MOVINGPLATFORM_H


#include "../../Engine/Object/Object.h"
#include "../../Engine/Rect/Rect.h"

class MovingPlatform : public Rect {
    sf::Vector2f pos1{};
    sf::Vector2f pos2{};
    float currentState{0};
    float speed{0.001};

    sf::Vector2f prevPos{};

public:
    explicit MovingPlatform(std::string const& uid);

    auto setPos1(sf::Vector2f p)-> void {
        pos1 = p;
    }

    auto setPos2(sf::Vector2f p) -> void  {
        pos2 = p;
    }

    void onBeforeStep(long long timeElapsed) override;
    bool onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) override;
};


#endif //PJC_PROJECT_MOVINGPLATFORM_H
