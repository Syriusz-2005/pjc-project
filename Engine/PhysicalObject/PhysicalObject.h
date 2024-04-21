
#ifndef PJC_PROJECT_PHYSICALOBJECT_H
#define PJC_PROJECT_PHYSICALOBJECT_H


class PhysicalObject {
public:
    const float mass;
    const float gravity = 0.001;

    bool isImmovable = false;

    explicit PhysicalObject(float mass = 1, float gravity = 0.01);
};


#endif //PJC_PROJECT_PHYSICALOBJECT_H
