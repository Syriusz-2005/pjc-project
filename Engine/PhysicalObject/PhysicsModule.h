
#ifndef PJC_PROJECT_PHYSICSMODULE_H
#define PJC_PROJECT_PHYSICSMODULE_H


class PhysicsModule {
public:
    const float mass;
    const float gravity = 0.001;

    bool isImmovable = false;

    explicit PhysicsModule(float mass = 1, float gravity = 0.01);
};


#endif //PJC_PROJECT_PHYSICSMODULE_H
