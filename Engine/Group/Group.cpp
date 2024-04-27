
#include "Group.h"

Group::Group(PhysicsModule &module, Layer layer) : Object(module, layer) {

}

auto Group::add(Object&o) -> void {
    objects.push_back(&o);
}

auto Group::getObjects() -> std::vector<Object*> const& {
    return objects;
}

auto Group::render(Context ctx) -> void {
    auto localCtx = Context(*ctx.window);

    localCtx.globalPos = ctx.globalPos + pos;

    for (auto object : objects) {
        object->render(localCtx);
    }
}

auto Group::setBoundingBox(sf::FloatRect const& box) -> void {
    area = &box;
}

auto Group::getBoundingBox() -> sf::FloatRect {
    return *area;
}

Group::~Group() = default;


