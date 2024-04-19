#include <iostream>
#include <fmt/core.h>
#include <SFML/Graphics.hpp>

class Scene {

};

auto main() -> int {
    fmt::println("Hello world!");

    auto window = sf::RenderWindow(
            sf::VideoMode({800, 600}), "Test",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}
