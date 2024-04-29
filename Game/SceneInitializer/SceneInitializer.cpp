#include "../../Engine/Scene/Scene.h"
#include "../Tree/Tree.h"
#include "../Ground/Ground.h"
#include <memory>
#include <random>

auto initializeTestScene(InitContext const& ctx) -> Scene * {
    auto scene = new Scene(sf::Color(150, 150, 150));
    auto shader = &scene->getBackgroundShader();
    shader->loadFromFile("../shaders/paper.vert", "../shaders/paper.frag");
    scene->setBackgroundSource(SHADER);
    scene->setBackground("../assets/background.png");
    std::srand(70);

    auto trees = std::vector<std::shared_ptr<Tree>>();

    for (int i = 0; i < 30; i++) {
        auto spread = (std::rand() % 400) + 100;
        auto tree = std::make_shared<Tree>((float) i * spread, ctx);
        trees.push_back(tree);
    }
    auto compare = [](const std::shared_ptr<Tree>& a, const std::shared_ptr<Tree>& b) -> bool {
        return a->getZDistance() > b->getZDistance();
    };
    std::ranges::sort(trees.begin(), trees.end(), compare);

    for (const auto& tree : trees) {
        scene->add(tree);
    }

    auto floor = std::make_shared<Ground>(
            *ctx.textureLoader->getTexture(GROUND),
            sf::Vector2f{0, -190});
    floor->setPos(sf::Vector2f(0, 850));
    fmt::println("{}", floor->getBoundingBox().top);
    scene->add(floor);

    return scene;
};