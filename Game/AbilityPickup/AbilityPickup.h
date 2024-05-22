
#ifndef PJC_PROJECT_ABILITYPICKUP_H
#define PJC_PROJECT_ABILITYPICKUP_H


#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../../Engine/TextureLoader/TextureLoader.h"
#include "../InitContext/InitContext.h"

class AbilityPickup : public TexturedRect {
public:
    explicit AbilityPickup(TextureLoader<TextureId> const* loader,  std::string const& uid);

    bool onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) override;
};


#endif //PJC_PROJECT_ABILITYPICKUP_H
