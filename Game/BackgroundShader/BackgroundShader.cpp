
#include "BackgroundShader.h"

BackgroundShader::BackgroundShader() {
    shader.loadFromFile("../shaders/background.vsh", "../shaders/background.fsh");
}

auto BackgroundShader::getShader() -> sf::Shader * {
    return &shader;
}
