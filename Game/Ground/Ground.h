

#ifndef PJC_PROJECT_GROUND_H
#define PJC_PROJECT_GROUND_H
#include <SFML/Graphics.hpp>
#include "../../Engine/Object/Object.h"
#include "../../Engine/TexturedRect/TexturedRect.h"
#include "../../Engine/TextureLoader/TextureLoader.h"
#include "../InitContext/InitContext.h"


class Ground : public TexturedRect {
public:
    explicit Ground(TextureLoader<TextureId> const& loader, std::string uid);
};


#endif //PJC_PROJECT_GROUND_H
