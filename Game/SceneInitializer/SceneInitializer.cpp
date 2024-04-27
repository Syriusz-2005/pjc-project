#include "../../Engine/Scene/Scene.h"
#include "../../Engine/Rect/Rect.h"


auto initializeTestScene() -> Scene * {
    auto scene = new Scene(sf::Color(240, 240, 240));
    auto floorObj = PhysicsModule();
    floorObj.isImmovable = true;
    auto floor = new Rect(floorObj, sf::Vector2f(800, 100));
    floor->name = "Floor";
    floor->setPos(sf::Vector2f(0, 550));
    scene->add(*floor);
    return scene;
};