

#ifndef PJC_PROJECT_BACKGROUNDSHADER_H
#define PJC_PROJECT_BACKGROUNDSHADER_H
#include <SFML/Graphics.hpp>


class BackgroundShader {
private:
    sf::Shader shader{sf::Shader()};
public:
    BackgroundShader();
    auto getShader() -> sf::Shader *;
};


#endif //PJC_PROJECT_BACKGROUNDSHADER_H
