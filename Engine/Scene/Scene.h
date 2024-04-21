#include <vector>
#include "../Object/Object.h"

#ifndef PJC_PROJECT_SCENE_H
#define PJC_PROJECT_SCENE_H


class Scene {
private:
    std::vector<Object*> objects = std::vector<Object*>();
    sf::Color clearColor;

public:
    explicit Scene(sf::Color clearColor);
    auto add(Object& o) -> void;
    auto render(Context ctx) -> void;
};


#endif //PJC_PROJECT_SCENE_H
