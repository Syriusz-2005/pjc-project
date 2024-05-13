#include "../../Engine/Scene/Scene.h"
#include "../Tree/Tree.h"
#include "../Ground/Ground.h"
#include "../SpikedGround/SpikedGround.h"
#include "../GroundPlatformSmall/GroundPlatformSmall.h"
#include "../BallEnemy/BallEnemy.h"
#include "../../Engine/Rect/Rect.h"
#include "../Splash/Splash.h"
#include "../MovingPlatform/MovingPlatform.h"
#include "../SpikeBallObstacle/SpikeBallObstacle.h"
#include "../Button/Button.h"
#include "../TextField/TextField.h"
#include "../States/States.h"
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
    auto scene = new Scene(sf::Color(150, 150, 150), "platform_madness", sf::Vector2f{50, 700});
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
    platform1->setPos1(sf::Vector2f(680, 860));
    platform1->setPos2(sf::Vector2f{880, 860});
    scene->add(platform1);

    auto platform2 = std::make_shared<MovingPlatform>("platform_2");
    platform2->setPos1(sf::Vector2f(1190, 860));
    platform2->setPos2(sf::Vector2f{1450, 860});
    platform2->setCurrentState(3.14);
    scene->add(platform2);

    auto floor2 = std::make_shared<GroundPlatformSmall>(*ctx.textureLoader, "floor2");
    floor2->setPos(sf::Vector2f(2000, 850));
    floor2->isSavable = false;
    scene->add(floor2);

    auto platform3 = std::make_shared<MovingPlatform>("platform_3");
    platform3->setPos1(sf::Vector2f(2450, 1080));
    platform3->setPos2(sf::Vector2f{2450, 450});
    scene->add(platform3);

    auto platform4 = std::make_shared<MovingPlatform>("platform_4");
    platform4->setPos1(sf::Vector2f(1450, 160));
    platform4->setPos2(sf::Vector2f{1880, 160});
    scene->add(platform4);

    auto obstacle1 = std::make_shared<SpikeBallObstacle>(*ctx.textureLoader, "obstacle_1");
    obstacle1->setPos(1830, 60);
    obstacle1->isSavable = false;
    scene->add(obstacle1);

    return scene;
}

auto initializeGameMenu(InitContext const& ctx) -> Scene* {
    auto scene = new Scene(sf::Color(150, 150, 150), "game_menu", sf::Vector2f{0, 0}, false);
    auto shader = &scene->getBackgroundShader();
    shader->loadFromFile("../shaders/paper.vert", "../shaders/paper.frag");
    scene->setBackgroundSource(SHADER);
    scene->setBackground("../assets/background.png");

    auto title = std::make_shared<TexturedRect>(
            PhysicsModule(),
            "game_title",
            *ctx.textureLoader->getTexture(GAME_TITLE),
            sf::Vector2f{0, 0},
            BACKGROUND);
    title->setPos(-title->getBoundingBox().width / 2, -800);
    title->isSavable = false;
    scene->add(title);

    auto newGameButton = std::make_shared<Button>("new_game_button", "New game");
    newGameButton->setPos(-newGameButton->getBoundingBox().width / 2, -140);
    newGameButton->isSavable = false;
    scene->add(newGameButton);

    auto selectGameButton = std::make_shared<Button>("select_game_button", "Select game");
    selectGameButton->setPos(-selectGameButton->getBoundingBox().width / 2, -40);
    selectGameButton->isSavable = false;
    scene->add(selectGameButton);

    auto nameGameField = std::make_shared<TextField>("name_game_field", FOCUSED_INPUT_ID, FOCUSED_INPUT_TEXT);
    nameGameField->setPos(-nameGameField->getBoundingBox().width / 2, -140);
    nameGameField->isSavable = false;
    nameGameField->isVisible = false;
    scene->add(nameGameField);

    auto submitNameButton = std::make_shared<Button>("submit_game_name_button", "Create");
    submitNameButton->setPos(-nameGameField->getBoundingBox().width / 2, -40);
    submitNameButton->isSavable = false;
    submitNameButton->isVisible = false;
    scene->add(submitNameButton);

    return scene;
}