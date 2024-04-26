#include <iostream>
#include <fmt/core.h>
#include <SFML/Graphics.hpp>

#include "Engine/Context/Context.h"
#include "Engine/Object/Object.h"
#include "Engine/Scene/Scene.h"
#include "Engine/Camera/Camera.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Rect/Rect.h"
#include "Game/Player/Player.h"

auto main() -> int {

    auto window = sf::RenderWindow(
            sf::VideoMode({800, 600}), "Pjc_project",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    auto ctx = Context(window);

    auto scene = Scene(sf::Color(255, 255, 255));

    auto camera = Camera();

    auto renderer = Renderer(ctx);

    auto floorObj = PhysicsModule();
    floorObj.isImmovable = true;
    auto floor = Rect(floorObj, sf::Vector2f(800, 100));
    floor.name = "Floor";
    floor.setPos(sf::Vector2f(0, 550));
    scene.add(floor);

    camera.setPos(sf::Vector2f(-100, 0));

    auto player = Player();
    scene.add(player);

    auto clock = sf::Clock();
    while (window.isOpen()) {
        auto timeDelta = clock.getElapsedTime();
        scene.getPhysicsEngine().step( std::min(timeDelta.asMicroseconds(), (long long) 1000 * 20));
        clock.restart();
        renderer.render(scene, camera);
        player.dispatchEvents(window);
        window.display();
    }
}
