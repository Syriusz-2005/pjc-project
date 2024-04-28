

#ifndef PJC_PROJECT_PHYSICSENGINE_H
#define PJC_PROJECT_PHYSICSENGINE_H


class PhysicsEngine {
private:
    std::vector<std::shared_ptr<Object>>* objects;
    auto getMiddlePos(Object& o) const -> sf::Vector2f;
    auto getMiddlePos(sf::FloatRect rect) const -> sf::Vector2f;
    auto applyCollision(std::shared_ptr<Object> o) const -> void;
    static auto getIntersectionArea(sf::Rect<float> a, sf::Rect<float> b) -> sf::Rect<float>*;
    auto applyCollisionForces(Object& a, Object& b, sf::FloatRect const&i) const -> void;

public:
    explicit PhysicsEngine(std::vector<std::shared_ptr<Object>> &objects);

    auto step(long long timeElapsed) const -> void;
};


#endif //PJC_PROJECT_PHYSICSENGINE_H
