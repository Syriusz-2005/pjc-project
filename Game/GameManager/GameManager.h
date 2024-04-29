
#ifndef PJC_PROJECT_GAMEMANAGER_H
#define PJC_PROJECT_GAMEMANAGER_H


#include <memory>

#include "../../Engine/Scene/Scene.h"
#include "../../Engine/Camera/Camera.h"
#include "../../Engine/Renderer/Renderer.h"
#include "../SceneInitializer/SceneInitializer.h"
#include "../Player/Player.h"
#include "../../Engine/TextureLoader/TextureLoader.h"
#include "../../Engine/GameStateController/GameStateController.h"

class GameManager : public Savable {
private:
    GameStateController gameStateController{this, "../state.splash.json"};

    Scene* testScene;
    Camera camera = Camera();
    sf::RenderWindow* window;
    Context drawContext;
    Renderer renderer;
    TextureLoader<TextureId> textureLoader{};
    std::shared_ptr<Player> player;
    Scene* currentScene = testScene;

public:
    explicit GameManager(sf::RenderWindow & window);

    ~GameManager() {
        fmt::println("Disposing game manager");
        delete testScene;
        fmt::println("{}", player.use_count());
        player.reset();
    }

    auto switchScene() -> void;
    auto startGameLoop() -> void;

    bool isUidMatch(std::string &id) override {return false;}
    void load(const nlohmann::json &json) override;
    std::unique_ptr<nlohmann::json> save() override;

    auto saveGame() -> void;
};


#endif //PJC_PROJECT_GAMEMANAGER_H
