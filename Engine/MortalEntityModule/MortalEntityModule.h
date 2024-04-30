
#ifndef PJC_PROJECT_MORTALENTITYMODULE_H
#define PJC_PROJECT_MORTALENTITYMODULE_H

#include <functional>
#include "../EntityModule/EntityModule.h"


class MortalEntityModule : public EntityModule {
private:
    float hp;
    std::function<void()>const& onDeath;
public:
    explicit MortalEntityModule(float hp, std::function<void()> const& onDeath = []() -> void {});

    void damage(float val) override;
};


#endif //PJC_PROJECT_MORTALENTITYMODULE_H
