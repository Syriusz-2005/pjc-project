#include "../../Engine/Scene/Scene.h"
#include "../../Engine/Rect/Rect.h"
#include "../Tree/Tree.h"
#include "../Ground/Ground.h"


auto initializeTestScene() -> Scene * {
    auto scene = new Scene(sf::Color(220, 220, 220));

//    auto floorObj = PhysicsModule();
//    floorObj.isImmovable = true;
//    auto floor = new Rect(floorObj, sf::Vector2f(2600, 800));
//    floor->name = "Floor";
//    floor->setPos(sf::Vector2f(0, 850));
//    scene->add(*floor);

    auto floor = new Ground();
    floor->physicsModule.isImmovable = true;
    floor->setPos(sf::Vector2f(0, 850));
    scene->add(*floor);

    auto tree = new Tree();
    scene->add(*tree);

    return scene;
};