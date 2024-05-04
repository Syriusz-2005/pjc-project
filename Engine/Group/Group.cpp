
#include "Group.h"

Group::Group(PhysicsModule &module, std::string uid, Layer layer) : Object(module, uid, layer) {

}

auto Group::add(Object&o) -> void {
    objects.push_back(&o);
}

auto Group::getObjects() -> std::vector<Object*> const& {
    return objects;
}

auto Group::render(Context ctx) -> void {
    auto localCtx = Context(*ctx.window, *ctx.font);

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


