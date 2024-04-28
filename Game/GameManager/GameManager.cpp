

#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &window)
    : window(&window),
    drawContext(Context(window)),
    renderer(Renderer(this->drawContext)) {
    textureLoader.registerTexture(GROUND, "../assets/grass.png");
    textureLoader.registerTexture(TREE, "../assets/tree.png");
    textureLoader.registerTexture(PLAYER_STILL, "../assets/player_still.png");

    auto initContext = InitContext{&textureLoader};
    testScene = initializeTestScene(initContext);
    currentScene = testScene;

    player = std::make_shared<Player>(initContext);

    currentScene->add(player);
}

auto GameManager::startGameLoop() -> void {
    auto clock = sf::Clock();
    while (window->isOpen()) {
        auto timeDelta = clock.getElapsedTime();
//        fmt::println("{}", timeDelta.asMilliseconds());
        currentScene->getPhysicsEngine().step( std::min(timeDelta.asMicroseconds(), (long long) 1000 * 20));
        clock.restart();
        auto size = window->getSize();
        camera.setPos(player->getPos() - sf::Vector2f(size.x / 2, size.y / 1.3));
        renderer.render(*currentScene, camera);
        window->display();
        player->dispatchEvents(*window);
    }
}

auto GameManager::switchScene() -> void {
//    currentScene = testScene;
}
