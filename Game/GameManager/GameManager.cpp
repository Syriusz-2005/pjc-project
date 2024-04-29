

#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &window)
    : window(&window),
    drawContext(Context(window)),
    renderer(Renderer(this->drawContext)) {
    textureLoader.registerTexture(GROUND, "../assets/grass.png");
    textureLoader.registerTexture(TREE, "../assets/tree.png");
    textureLoader.registerTexture(PLAYER_STILL, "../assets/player_still.png");
    textureLoader.registerTexture(SPIKES_GROUND, "../assets/spikes.png");
    textureLoader.registerTexture(GROUND_PLATFORM_SMALL, "../assets/ground_small_platform.png");

    auto initContext = InitContext{&textureLoader};
    testScene = initializeTestScene(initContext);
    currentScene = testScene;

    player = std::make_shared<Player>(initContext, "player0");
    player->setPos(sf::Vector2f{50, 700});
    player->setSpawnPoint();
    currentScene->add(player);

    gameStateController.loadIfExists();
}

auto GameManager::startGameLoop() -> void {
    auto clock = sf::Clock();
    auto tickClock = sf::Clock();
    while (window->isOpen()) {
        auto timeDelta = clock.getElapsedTime();
//        fmt::println("{}", timeDelta.asMilliseconds());
        tickClock.restart();
        currentScene->getPhysicsEngine().step( std::min(timeDelta.asMicroseconds(), (long long) 1000 * 20));
        clock.restart();
        auto size = window->getSize();
        camera.setPos(player->getPos() - sf::Vector2f(size.x / 2, size.y / 1.3));
        renderer.render(*currentScene, camera);
        window->display();
        auto tickDelta = tickClock.getElapsedTime();
//        fmt::println("tick delta: {} ms", (float) tickDelta.asMicroseconds() / 1000);
        player->dispatchEvents(*window);
    }
}

auto GameManager::switchScene() -> void {
//    currentScene = testScene;
}

void GameManager::load(const nlohmann::json &json) {
    player->load(json["player"]);
    for (auto sceneData : json["scenes"]) {
        auto id = sceneData["uid"].get<std::string>();
        if (testScene->isUidMatch(id)) {
            testScene->load(sceneData);
        }
    }
}

std::unique_ptr<nlohmann::json> GameManager::save() {
    auto json = std::make_unique<nlohmann::json>();
    (*json)["player"] = *player->save();
    fmt::println("Player saved");
    (*json)["scenes"].push_back(*testScene->save());
    return json;
}

auto GameManager::saveGame() -> void {
    gameStateController.saveToFile();
}
