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
            sf::VideoMode({800, 600}), "Pjc_project",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );

    auto manager = GameManager(window);
    manager.startGameLoop();
}
