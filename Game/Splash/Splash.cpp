#include "Splash.h"
#include "../../Engine/VecUtils/VecUtils.h"
#include "../ObjectType/ObjectType.h"
#include "../States/States.h"

Splash::Splash(std::string const &uid) : Object(PhysicsModule(0, 0, 0), uid, BACKGROUND) {
    name = "Splash teleport";
    info.setPos(100, 0);
}

void Splash::render(Context ctx) {
    auto globalPos = pos + ctx.globalPos;

    auto shader = ctx.splashShader->getShader();
    shape.setPosition(globalPos);
//    shader->setUniform("size", shape.getSize());
    shader->setUniform("frame", ctx.frame);
    ctx.window->draw(shape, shader);
    ctx.globalPos += pos;
    if (displayInfo) {
        info.render(ctx);
    }
}

sf::FloatRect Splash::getBoundingBox() {
    return sf::FloatRect{pos, shape.getSize()};
}

bool Splash::onBeforeCollision(const std::shared_ptr<Object> &collisionTarget) {
    Object::onBeforeCollision(collisionTarget);
    if (collisionTarget->getType() == PLAYER) {
        auto middle = pos + vec::divide(shape.getSize(), 2);
        auto distance = vec::distance(middle, collisionTarget->getPos());
        displayInfo = distance < 230;
        parent->state.set(IS_FIRST_SPLASH_ACTIVE, displayInfo);
    }
    return true;
}
