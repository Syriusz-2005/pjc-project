

#ifndef PJC_PROJECT_PHYSICSENGINE_H
#define PJC_PROJECT_PHYSICSENGINE_H


class PhysicsEngine {
private:
    std::vector<Object *>* objects;
public:
    explicit PhysicsEngine(std::vector<Object *> &objects);

    auto step() -> void;
};


#endif //PJC_PROJECT_PHYSICSENGINE_H
