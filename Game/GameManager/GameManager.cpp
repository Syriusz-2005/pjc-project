

#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &window)
        : window(&window), drawContext(Context(window)), renderer(Renderer(this->drawContext)), player(Player()) {
    currentScene->add(player);
    camera.setPos(sf::Vector2f(0, 0));
}

auto GameManager::startGameLoop() -> void {
    auto clock = sf::Clock();
    while (window->isOpen()) {
        auto timeDelta = clock.getElapsedTime();
//        fmt::println("{} ms", timeDelta.asMilliseconds());
        currentScene->getPhysicsEngine().step( std::min(timeDelta.asMicroseconds(), (long long) 1000 * 20));
        clock.restart();
        auto size = window->getSize();
        camera.setPos(player.getPos() - sf::Vector2f(size.x / 2, size.y / 1.3));
        renderer.render(*currentScene, camera);
        player.dispatchEvents(*window);
        window->display();
    }
}

auto GameManager::switchScene() -> void {
//    currentScene = testScene;
}
