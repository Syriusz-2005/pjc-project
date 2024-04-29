

#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &window)
    : window(&window),
    drawContext(Context(window)),
    renderer(Renderer(this->drawContext)) {
    textureLoader.registerTexture(GROUND, "../assets/grass.png");
    textureLoader.registerTexture(TREE, "../assets/tree.png");
    textureLoader.registerTexture(PLAYER_STILL, "../assets/player_still.png");
    textureLoader.registerTexture(SPIKES_GROUND, "../assets/spikes.png");

    auto initContext = InitContext{&textureLoader};
    testScene = initializeTestScene(initContext);
    currentScene = testScene;

    player = std::make_shared<Player>(initContext);
    player->setPos(sf::Vector2f{50, 700});
    player->setSpawnPoint();
    currentScene->add(player);
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
