
#ifndef PJC_PROJECT_GAMEMANAGER_H
#define PJC_PROJECT_GAMEMANAGER_H


#include <memory>

#include "../../Engine/Scene/Scene.h"
#include "../../Engine/Camera/Camera.h"
#include "../../Engine/Renderer/Renderer.h"
#include "../SceneInitializer/SceneInitializer.h"
#include "../Player/Player.h"
#include "../../Engine/TextureLoader/TextureLoader.h"

class GameManager {
private:
    Scene* testScene;
    Camera camera = Camera();
    sf::RenderWindow* window;
    Context drawContext;
    Renderer renderer;
    std::shared_ptr<Player> player = std::make_shared<Player>(Player());
    TextureLoader<TextureId> textureLoader{};

    Scene* currentScene = testScene;
public:
    explicit GameManager(sf::RenderWindow & window);

    ~GameManager() {
        delete testScene;
    }

    auto switchScene() -> void;
    auto startGameLoop() -> void;
};


#endif //PJC_PROJECT_GAMEMANAGER_H
