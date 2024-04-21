
#include "Scene.h"


auto Scene::add(Object &o) -> void {
    objects.push_back(&o);
}

auto Scene::render(Context ctx) -> void {
    ctx.window->clear(clearColor);
    for (auto object : objects) {
        object->render(ctx);
    }
}

Scene::Scene(sf::Color clearColor): clearColor(clearColor) {

}
