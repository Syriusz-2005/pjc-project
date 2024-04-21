#include <iostream>
#include <fmt/core.h>
#include <SFML/Graphics.hpp>

#include "Engine/Context/Context.h"
#include "Engine/Object/Object.h"
#include "Engine/Scene/Scene.h"
#include "Engine/Camera/Camera.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Rect/Rect.h"

auto main() -> int {

    auto window = sf::RenderWindow(
            sf::VideoMode({800, 600}), "Pjc_project",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    auto ctx = Context(window);

    auto scene = Scene(sf::Color(255, 255, 255));
    auto camera = Camera();

    auto renderer = Renderer(scene, camera, ctx);

    auto rect = Rect();
    scene.add(rect);

    camera.setPos(sf::Vector2f(-100, 0));

    while (window.isOpen()) {
        renderer.render();
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}
