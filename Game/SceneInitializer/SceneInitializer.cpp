#include "../../Engine/Scene/Scene.h"
#include "../Tree/Tree.h"
#include "../Ground/Ground.h"
#include "../SpikedGround/SpikedGround.h"
#include "../GroundPlatformSmall/GroundPlatformSmall.h"
#include "../BallEnemy/BallEnemy.h"
#include "../../Engine/Rect/Rect.h"
#include "../Splash/Splash.h"
#include "../MovingPlatform/MovingPlatform.h"
#include <memory>
#include <random>

auto initializeTestScene(InitContext const& ctx) -> Scene * {
    auto scene = new Scene(sf::Color(150, 150, 150), "test_scene", sf::Vector2f{50, 700});
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

    auto splash = std::make_shared<Splash>("splash_1");
    splash->isSavable = false;
    splash->setPos(3340, 490);
    scene->add(splash);

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
    floor3->setPos(sf::Vector2f(1800, 950));
    scene->add(floor3);

    auto groundRect = std::make_shared<Rect>(
            PhysicsModule(0, 0, 0),
            "ground_rect",
            sf::Vector2f{4000, 400},
            BACKGROUND);
    groundRect->setPos(sf::Vector2f{0, 980});
    scene->add(groundRect);

    auto groundRect2 = std::make_shared<Rect>(
            PhysicsModule(0, 0, 0),
            "ground_rect_2",
            sf::Vector2f{2000, 400},
            BACKGROUND);
    groundRect2->setPos(sf::Vector2f{-2000, 800});
    scene->add(groundRect2);

    auto groundRect3 = std::make_shared<Rect>(
            PhysicsModule(0, 0, 0),
            "ground_rect_3",
            sf::Vector2f{2000, 400},
            BACKGROUND);
    groundRect3->setPos(sf::Vector2f{3600, 900});
    scene->add(groundRect3);


    auto platform = std::make_shared<GroundPlatformSmall>(*ctx.textureLoader, "platform");
    platform->setPos(sf::Vector2f(2600, 820));
    scene->add(platform);


    auto wallRight = std::make_shared<Ground>(*ctx.textureLoader, "wall_right");
    wallRight->setPos(sf::Vector2f(3800, 650));
    scene->add(wallRight);

    auto enemy1 = std::make_shared<BallEnemy>(*ctx.textureLoader, "ball_enemy1");
    enemy1->setPos(sf::Vector2f(2650, 710));
    scene->add(enemy1);

    auto testText = std::make_shared<TextDisplay>("test_text", "This is a test text");
    testText->isSavable = false;
    scene->add(testText);

    return scene;
};

auto initializePlatformMadness(InitContext const& ctx) -> Scene* {
    auto scene = new Scene(sf::Color(150, 150, 150), "test_scene", sf::Vector2f{50, 700});
    auto shader = &scene->getBackgroundShader();
    shader->loadFromFile("../shaders/paper.vert", "../shaders/paper.frag");
    scene->setBackgroundSource(SHADER);
    scene->setBackground("../assets/background.png");
    std::srand(80);

    auto trees = std::vector<std::shared_ptr<Tree>>();

    for (int i = 0; i < 15; i++) {
        auto spread = (std::rand() % 450) + 140;
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

    auto floor = std::make_shared<GroundPlatformSmall>(*ctx.textureLoader, "floor1");
    floor->setPos(sf::Vector2f(0, 850));
    floor->isSavable = false;
    scene->add(floor);

    auto platform1 = std::make_shared<MovingPlatform>("platform_1");
    platform1->setPos1(sf::Vector2f(500, 760));
    platform1->setPos2(sf::Vector2f{700, 760});
    scene->add(platform1);

    return scene;
}