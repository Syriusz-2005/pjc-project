
#ifndef PJC_PROJECT_GAMEMANAGER_H
#define PJC_PROJECT_GAMEMANAGER_H


#include <memory>
#include <variant>

#include "../../Engine/Scene/Scene.h"
#include "../../Engine/Camera/Camera.h"
#include "../../Engine/Renderer/Renderer.h"
#include "../SceneInitializer/SceneInitializer.h"
#include "../Player/Player.h"
#include "../../Engine/TextureLoader/TextureLoader.h"
#include "../../Engine/GameStateController/GameStateController.h"
#include "../States/States.h"

/**
 * Game manager for the "Splash" game
 * The whole system is designed to be "good enough". There's lots of room for potential improvement and optimization.
 */
class GameManager : public Savable {
private:
    GameStateController gameStateController{this, "../state.splash.json"};

    Scene* testScene;
    Scene* verticalScene;

    Camera camera = Camera();
    sf::RenderWindow* window;
    sf::Font defaultFont{};
    Context drawContext;
    Renderer renderer;
    TextureLoader<TextureId> textureLoader{};
    std::function<void()> onPlayerDeath = [this]() -> void {
        fmt::println("Player died, resetting scene...");
        delete testScene;
        auto initContext = InitContext{&textureLoader};
        initScenes(initContext);
        currentScene->add(player);
        gameStateController.loadIfExists();
    };
    std::shared_ptr<Player> player;
    Scene* currentScene = testScene;

    auto initScenes(InitContext& initContext) -> void;
public:
    explicit GameManager(sf::RenderWindow & window);

    ~GameManager() {
        fmt::println("Disposing game manager");
        delete testScene;
        player.reset();
    }

    auto switchScene() -> void;
    auto startGameLoop() -> void;

    bool isUidMatch(std::string const &id) const override {return false;}
    void load(const nlohmann::json &json) override;
    std::unique_ptr<nlohmann::json> save() override;

    auto saveGame() -> void;
};


#endif //PJC_PROJECT_GAMEMANAGER_H
