

#ifndef PJC_PROJECT_PHYSICSENGINE_H
#define PJC_PROJECT_PHYSICSENGINE_H


class PhysicsEngine {
private:
    std::vector<Object *>* objects;
    auto getMiddlePos(Object *o) -> sf::Vector2f;
    auto getMiddlePos(sf::FloatRect rect) -> sf::Vector2f;
    auto applyCollision(Object * o) -> void;
    static auto getIntersectionArea(sf::Rect<float> a, sf::Rect<float> b) -> sf::Rect<float>*;
    auto applyCollisionForces(Object *a, Object *b, sf::FloatRect &i) -> void;

public:
    explicit PhysicsEngine(std::vector<Object *> &objects);

    auto step() -> void;
};


#endif //PJC_PROJECT_PHYSICSENGINE_H
