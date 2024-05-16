
#ifndef PJC_PROJECT_GAMEMANAGER_H
#define PJC_PROJECT_GAMEMANAGER_H


#include <memory>
#include <variant>
#include <regex>

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
    GameStateController gameStateController{this, "../"};
    std::string currentSaveName{};

    Scene* testScene;
    Scene* platformMadness;
    Scene* gameMenu;

    Camera camera{};
    sf::RenderWindow* window;
    sf::Font defaultFont{};
    Context drawContext;
    Renderer renderer;
    TextureLoader<TextureId> textureLoader{};
    std::function<void()> onPlayerDeath = [this]() -> void {
        fmt::println("Player died, resetting scene...");
        delete testScene;
        delete platformMadness;
        delete gameMenu;
        auto gameNames = gameStateController.listSaveNames();
        auto initContext = InitContext{&textureLoader, *window, camera, gameNames};
        initScenes(initContext);
        currentScene->add(player);
        player->setPos(currentScene->getSpawn());
        gameStateController.loadIfExists(currentSaveName);
    };
    std::function<void()> onSwitchScene = [this]() -> void {
        switchScene();
    };
    std::function<void()> onAddNewGame = [this]() -> void {
        fmt::println("Switching to the add game menu");
        gameMenu->forEach(
                std::vector<std::string>{"new_game_button", "select_game_button"},
                [](Object& b) { b.isVisible = false; }
                );
        auto nameGameInputId = std::string{"name_game_field"};
        auto selectGameButtons = gameMenu->getChildren([nameGameInputId](Object& o) -> bool {
            return o.isUidMatch(nameGameInputId) or o.isUidMatch("submit_game_name_button");
        });
        for (auto& selectGameButton : selectGameButtons) {
            selectGameButton->isVisible = true;
        }
        gameMenu->state.set(FOCUSED_INPUT_ID, nameGameInputId);
        player->setInputMode(inputMode::TEXT_INSERT);
    };
    std::function<void()> onSubmitNewGameName = [this]() -> void {
        auto gameName = player->getEnteredText();
        player->setInputMode(inputMode::GAME_CONTROL);
        // Source: https://en.cppreference.com/w/cpp/regex
        std::regex allowedChars("[^a-zA-Z_]");
        auto sanitisedGameName = std::regex_replace(gameName, allowedChars, "_");
        fmt::println("Opening a new game: {}", sanitisedGameName, gameName);
        currentSaveName = sanitisedGameName;
        setScene(testScene->getUid());
    };
    std::function<void()> onSaveSelectorOpen = [this]() -> void {
        fmt::println("Save selector opened");
        gameMenu->forEach(
                std::vector<std::string>{"new_game_button", "select_game_button"},
                [](Object& b) { b.isVisible = false; }
        );
        gameMenu->forEach(
                std::vector<std::string>{"choose_save_title"},
                [](Object& b) { b.isVisible = true; });

        for (auto& enterSaveButton : gameMenu->getChildren([](Object& o) -> bool {return o.getUid().starts_with("save_enter_button_");})) {
            enterSaveButton->isVisible = true;
        }
    };
    std::function<void()> onSaveSelected = [this]() -> void {
        auto uid = player->getClickedButtonUid();
        // Crappy
        auto saveName = regex_replace(uid, std::regex("save_enter_button_"), "");
        fmt::println("Save selected: {}", saveName);
        currentSaveName = saveName;
        gameStateController.loadIfExists(currentSaveName);
    };
    std::shared_ptr<Player> player;
    Scene* currentScene = testScene;

    auto initScenes(InitContext& initContext) -> void;
    auto setScene(std::string const& uid) -> void;
public:
    explicit GameManager(sf::RenderWindow & window);

    ~GameManager() {
        fmt::println("Disposing game manager");
        delete testScene;
        delete platformMadness;
        delete gameMenu;
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
