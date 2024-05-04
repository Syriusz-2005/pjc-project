

#ifndef PJC_PROJECT_SPLASHSHADER_H
#define PJC_PROJECT_SPLASHSHADER_H


#include "SFML/Graphics/Shader.hpp"

class SplashShader {
private:
    sf::Shader shader{sf::Shader()};
public:
    SplashShader();
    auto getShader() -> sf::Shader *;
};


#endif //PJC_PROJECT_SPLASHSHADER_H
