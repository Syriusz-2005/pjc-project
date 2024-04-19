#include <iostream>
#include <fmt/core.h>
#include <SFML/Graphics.hpp>

struct Context {
    sf::RenderWindow* window{};
    sf::Vector2f globalPos;
};

enum Layer {
    FOREGROUND,
    BACKGROUND,
};

class Object {
protected:
    sf::Vector2f pos = sf::Vector2f(0, 0);
    sf::Vector2f vel = sf::Vector2f(0, 0);
    Layer layer = FOREGROUND;
    float zDistance = 1;
public:

    auto getPos() -> sf::Vector2f {
        return pos;
    }

    auto getVel() -> sf::Vector2f {
        return vel;
    }

    virtual auto render(Context ctx) -> void {
        throw std::exception();
    };
};

class Rect : public Object {
protected:
    sf::RectangleShape s;

public:

    explicit Rect(sf::Vector2f size = sf::Vector2f(40, 40)) : Object() {
        s = sf::RectangleShape(size);
        s.setFillColor(sf::Color(0, 255, 255));
    }

    auto render(Context ctx) -> void override {
        auto globalPos = pos + ctx.globalPos;
        s.setPosition(globalPos);
        ctx.window->draw(s);
    }

};

class Scene {
private:
    std::vector<Object*> objects = std::vector<Object*>();

public:
    auto add(Object& o) -> void {
        objects.push_back(&o);
    }

    auto render(Context ctx) -> void {
        ctx.window->clear();
        for (auto object : objects) {
            object->render(ctx);
        }
    }
};

class Camera {
private:
    sf::Vector2f pos = sf::Vector2f(0, 0);

public:
    auto getPos() -> sf::Vector2f {
        return pos;
    }

    auto setPos(sf::Vector2f newPos) -> void {
        this->pos.x = newPos.x;
        this->pos.y = newPos.y;

    }
};

class Renderer {
private:
    Scene* scene;
    Camera* camera;
    Context* context;
public:
    Renderer(Scene& scene, Camera& camera, Context& ctx) {
        this->scene = &scene;
        this->camera = &camera;
        this->context = &ctx;
    }

    auto render() {
        auto cameraPos = camera->getPos();
        context->globalPos = -cameraPos;

        scene->render(*context);
    }
};

auto main() -> int {

    auto window = sf::RenderWindow(
            sf::VideoMode({800, 600}), "Pjc_project",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    auto ctx = Context();
    ctx.window = &window;

    auto scene = Scene();
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
