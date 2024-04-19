#include <iostream>
#include <fmt/core.h>
#include <SFML/Graphics.hpp>

struct Context {
    sf::RenderWindow* window;
    float timeDelta;
};

class Rect : Object {
protected:
    sf::RectangleShape s;

public:

    Rect(sf::Vector2f initialPos, sf::Vector2f size) : Object(initialPos) {
        s = sf::RectangleShape(size);
    }

    auto draw(Context ctx) -> void {
        auto shape = sf::RectangleShape(size);

        ctx.window->draw();
    }
};

class Scene {
private:
    std::vector<Object<sf::Drawable>> objects = std::vector<Object<sf::Drawable>>();

public:
    auto add(Object o) -> void {
        objects.push_back(o);
    }

    auto render(Context& ctx) -> void {
        ctx.window->clear();
        for (auto object : objects) {
            object.render(ctx);
        }
    }
};

auto main() -> int {
    fmt::println("Hello world!");

    auto window = sf::RenderWindow(
            sf::VideoMode({800, 600}), "Pjc_project",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    auto ctx = Context();
    ctx.window = &window;

    auto scene = Scene();

    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}
