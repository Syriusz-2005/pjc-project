
#ifndef PJC_PROJECT_PHYSICSMODULE_H
#define PJC_PROJECT_PHYSICSMODULE_H


class PhysicsModule {
public:
    const float mass;
    const float gravity;

    bool isImmovable = false;
    /**
     * Does it interact with other objects?
     */
    bool isEthereal = false;
    float bounciness = 1;

    bool isOnGround = false;

    explicit PhysicsModule(float mass = 1, float gravity = 0.0003, float bounciness = 1);
};


#endif //PJC_PROJECT_PHYSICSMODULE_H
