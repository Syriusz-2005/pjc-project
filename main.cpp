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
#include "Game/GameManager/GameManager.h"

auto main() -> int {
    auto window = sf::RenderWindow(
            sf::VideoMode({1700, 1000}), "Pjc_project",
            sf::Style::Default, sf::ContextSettings(0, 0, 0)
    );
    // temporary, because not limiting it causes the clear method to eat up CPU by a lot on my device (I assume due to the usage of Nvidia Gsync)
    window.setFramerateLimit(144);
    // With the cap enabled the game loop is crazy fast. Even the per-frame simulation doesn't matter
    // I must admit, c++ is fast, especially backed by an Opengl for rendering
    auto manager = GameManager(window);
    manager.startGameLoop();
    fmt::println("Quitting gracefully...");
    manager.saveGame();
    fmt::println("Game saved");
}
