#include "../../Engine/Scene/Scene.h"
#include "../Tree/Tree.h"
#include "../Ground/Ground.h"
#include "../SpikedGround/SpikedGround.h"
#include "../GroundPlatformSmall/GroundPlatformSmall.h"
#include <memory>
#include <random>

auto initializeTestScene(InitContext const& ctx) -> Scene * {
    auto scene = new Scene(sf::Color(150, 150, 150), "test_scene");
    auto shader = &scene->getBackgroundShader();
    shader->loadFromFile("../shaders/paper.vert", "../shaders/paper.frag");
    scene->setBackgroundSource(SHADER);
    scene->setBackground("../assets/background.png");
    std::srand(70);

    auto trees = std::vector<std::shared_ptr<Tree>>();

    for (int i = 0; i < 30; i++) {
        auto spread = (std::rand() % 400) + 100;
        auto tree = std::make_shared<Tree>((float) i * spread, "tree_" + std::to_string(i), ctx);
        trees.push_back(tree);
    }
    auto compare = [](const std::shared_ptr<Tree>& a, const std::shared_ptr<Tree>& b) -> bool {
        return a->getZDistance() > b->getZDistance();
    };
    std::ranges::sort(trees.begin(), trees.end(), compare);

    for (const auto& tree : trees) {
        scene->add(tree);
    }

    auto wall1 = std::make_shared<Ground>(*ctx.textureLoader, "wall1");
    wall1->setPos(sf::Vector2f(-1800, 600));
    scene->add(wall1);

    auto floor = std::make_shared<Ground>(*ctx.textureLoader, "floor1");
    floor->setPos(sf::Vector2f(0, 850));
    scene->add(floor);

    auto floor2 = std::make_shared<Ground>(*ctx.textureLoader, "floor2");
    floor2->setPos(sf::Vector2f(2000, 850));
    scene->add(floor2);

    auto floor3 = std::make_shared<SpikedGround>(*ctx.textureLoader, "floor3");
    floor3->setPos(sf::Vector2f(1800, 1050));
    scene->add(floor3);

    auto platform = std::make_shared<GroundPlatformSmall>(*ctx.textureLoader, "platform");
    platform->setPos(sf::Vector2f(2600, 820));
    scene->add(platform);

    return scene;
};