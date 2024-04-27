//
// Created by NOWY on 27.04.2024.
//

#include "BackgroundShader.h"

BackgroundShader::BackgroundShader() {
    shader.loadFromFile("../shaders/background.vsh", "../shaders/background.fsh");
}

auto BackgroundShader::getShader() -> sf::Shader * {
    return &shader;
}
