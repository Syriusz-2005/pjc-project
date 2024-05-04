
#include "SplashShader.h"

SplashShader::SplashShader() {
    shader.loadFromFile("../shaders/splash.vert", "../shaders/splash.frag");
}

auto SplashShader::getShader() -> sf::Shader * {
    return &shader;
}
