
#ifndef PJC_PROJECT_ENTITYMODULE_H
#define PJC_PROJECT_ENTITYMODULE_H


#include <memory>

class EntityModule {
public:
    virtual auto damage(float val) -> void;
};


#endif //PJC_PROJECT_ENTITYMODULE_H
