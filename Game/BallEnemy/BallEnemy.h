
#ifndef PJC_PROJECT_BALLENEMY_H
#define PJC_PROJECT_BALLENEMY_H

#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../InitContext/InitContext.h"
#include "../../Engine/MortalEntityModule/MortalEntityModule.h"

class BallEnemy : public TexturedRect {
private:
    std::function<void()> onDeath = [this]() -> void {
        parent->remove(this);
    };
    std::shared_ptr<EntityModule> entityModule = std::make_shared<MortalEntityModule>(10);
public:
    BallEnemy(TextureLoader<TextureId> const& loader, std::string const& uid);
};


#endif //PJC_PROJECT_BALLENEMY_H
