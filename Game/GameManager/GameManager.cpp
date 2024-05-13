

#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &window) : window(&window), drawContext(Context(window, defaultFont)),
                                                     renderer(Renderer(this->drawContext)) {
    // A texture atlas would be more efficient
    textureLoader.registerTexture(GROUND, "../assets/grass.png");
    textureLoader.registerTexture(TREE, "../assets/tree.png");
    textureLoader.registerTexture(PLAYER_STILL, "../assets/player_still.png");
    textureLoader.registerTexture(SPIKES_GROUND, "../assets/spikes.png");
    textureLoader.registerTexture(GROUND_PLATFORM_SMALL, "../assets/ground_small_platform.png");
    textureLoader.registerTexture(ENEMY_BALL, "../assets/enemy_ball.png");
    textureLoader.registerTexture(PLAYER_RUNNING_4, "../assets/player_running_4.png");
    textureLoader.registerTexture(PLAYER_RUNNING_5, "../assets/player_running_5.png");
    textureLoader.registerTexture(PLAYER_RUNNING_6, "../assets/player_running_6.png");
    textureLoader.registerTexture(PLAYER_RUNNING_7, "../assets/player_running_7.png");
    textureLoader.registerTexture(PLAYER_RUNNING_8, "../assets/player_running_8.png");
    textureLoader.registerTexture(PLAYER_RUNNING_9, "../assets/player_running_9.png");
    textureLoader.registerTexture(PLAYER_RUNNING_10, "../assets/player_running_10.png");
    textureLoader.registerTexture(PLAYER_RUNNING_11, "../assets/player_running_11.png");
    textureLoader.registerTexture(BACKLIGHT, "../assets/backlight.png");
    textureLoader.registerTexture(GAME_TITLE, "../assets/title.png");

    defaultFont.loadFromFile("../assets/GochiHand-Regular.ttf");

    auto initContext = InitContext{&textureLoader, window, camera};

    initScenes(initContext);

    player = std::make_shared<Player>(initContext, "player0");
    player->onMicrotask(DEATH, onPlayerDeath);
    player->onMicrotask(SWITCH_TO_NEXT_SCENE, onSwitchScene);
    player->onMicrotask(CREATE_NEW_GAME, onAddNewGame);
    player->onMicrotask(SUBMIT_NEW_GAME_NAME, onSubmitNewGameName);

    currentScene->add(player);

    player->setPos(currentScene->getSpawn());
    player->setIsSimulated(false);

    gameStateController.loadIfExists(currentSaveName);
}

auto GameManager::initScenes(InitContext &initContext) -> void {
    fmt::println("Initialising scenes...");
    testScene = initializeTestScene(initContext);
    platformMadness = initializePlatformMadness(initContext);
    gameMenu = initializeGameMenu(initContext);
    currentScene = gameMenu;
}

auto GameManager::startGameLoop() -> void {
    auto clock = sf::Clock();
    auto tickClock = sf::Clock();
    while (window->isOpen()) {
        auto timeDelta = clock.getElapsedTime();
//        fmt::println("{}", timeDelta.asMilliseconds());
        tickClock.restart();
        if (currentScene) {
            currentScene->getPhysicsEngine().step(std::min(timeDelta.asMicroseconds(), (long long) 1000 * 20));
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
}

auto GameManager::switchScene() -> void {
    currentScene->remove(player);

    if (currentScene == testScene) {
        currentScene = platformMadness;
        currentScene->add(player);
        player->setPos(currentScene->getSpawn());
    }
}

void GameManager::load(const nlohmann::json &json) {
    for (auto sceneData: json["scenes"]) {
        auto id = sceneData["uid"].get<std::string>();
        // Could be better? Sure.
        if (testScene->isUidMatch(id)) {
            testScene->load(sceneData);
        } else if (platformMadness->isUidMatch(id)) {
            platformMadness->load(sceneData);
        } else if (gameMenu->isUidMatch(id)) {
            gameMenu->load(sceneData);
        }
    }
    if (json.contains("currentSceneId")) {
        setScene(json["currentSceneId"]);
    }
}

std::unique_ptr<nlohmann::json> GameManager::save() {
    auto json = std::make_unique<nlohmann::json>();
    (*json)["scenes"].push_back(*testScene->save());
    (*json)["scenes"].push_back(*platformMadness->save());
    (*json)["scenes"].push_back(*gameMenu->save());
    (*json)["currentSceneId"] = currentScene->getUid();
    return json;
}

auto GameManager::saveGame() -> void {
    gameStateController.saveToFile(currentSaveName);
}

auto GameManager::setScene(const std::string &uid) -> void {
    currentScene->remove(player);
    if (testScene->isUidMatch(uid)) {
        currentScene = testScene;
    } else if (platformMadness->isUidMatch(uid)) {
        currentScene = platformMadness;
    }
    currentScene->add(player);
    player->setIsSimulated(true);
}

