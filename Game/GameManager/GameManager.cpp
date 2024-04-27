

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
        currentScene->getPhysicsEngine().step( std::min(timeDelta.asMicroseconds(), (long long) 1000 * 20));
        clock.restart();
        renderer.render(*currentScene, camera);
        player.dispatchEvents(*window);
        window->display();
    }
}

auto GameManager::switchScene() -> void {
//    currentScene = testScene;
}
