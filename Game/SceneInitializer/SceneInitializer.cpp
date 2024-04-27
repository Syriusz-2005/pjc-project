#include "../../Engine/Scene/Scene.h"
#include "../../Engine/Rect/Rect.h"
#include "../Tree/Tree.h"
#include "../Ground/Ground.h"
#include <random>

auto initializeTestScene() -> Scene * {
    auto scene = new Scene(sf::Color(220, 220, 220));

//    auto floorObj = PhysicsModule();
//    floorObj.isImmovable = true;
//    auto floor = new Rect(floorObj, sf::Vector2f(2600, 800));
//    floor->name = "Floor";
//    floor->setPos(sf::Vector2f(0, 850));
//    scene->add(*floor);


    std::srand(70);

    auto trees = std::vector<Tree*>();

    for (int i = 0; i < 60; i++) {
        auto spread = (std::rand() % 400) + 200;
        auto tree = new Tree((float) i * spread);
        trees.push_back(tree);
    }
    auto compare = [](Tree const* a, Tree const* b) -> bool {
        return a->getZDistance() > b->getZDistance();
    };
    std::ranges::sort(trees.begin(), trees.end(), compare);

    for (auto tree : trees) {
        scene->add(*tree);
    }

    auto floor = new Ground();
    floor->physicsModule.isImmovable = true;
    floor->setPos(sf::Vector2f(0, 850));
    scene->add(*floor);

    return scene;
};