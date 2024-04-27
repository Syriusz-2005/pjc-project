
#ifndef PJC_PROJECT_GAMEMANAGER_H
#define PJC_PROJECT_GAMEMANAGER_H


#include "../../Engine/Scene/Scene.h"
#include "../../Engine/Camera/Camera.h"
#include "../../Engine/Renderer/Renderer.h"
#include "../SceneInitializer/SceneInitializer.h"
#include "../Player/Player.h"

class GameManager {
private:
    Scene * testScene = initializeTestScene();
    Camera camera = Camera();
    sf::RenderWindow * window;
    Context drawContext;
    Renderer renderer;
    Player player;

    Scene * currentScene = testScene;
public:
    explicit GameManager(sf::RenderWindow & window);

    ~GameManager() {
        delete testScene;
    }

    auto switchScene() -> void;
    auto startGameLoop() -> void;
};


#endif //PJC_PROJECT_GAMEMANAGER_H