
#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "../../Engine/Group/Group.h"
#include "../../Engine/Rect/Rect.h"
#include "../InitContext/InitContext.h"
#include "../../Engine/MortalEntityModule/MortalEntityModule.h"
#include "../../Engine/EventEmitter/EventEmitter.h"
#include "../../Engine/TextureSwitcher/TextureSwitcher.h"
#include "../../Engine/Camera/Camera.h"

enum PlayerEventType {
        DEATH,
        SWITCH_TO_NEXT_SCENE,
        CREATE_NEW_GAME,
        SUBMIT_NEW_GAME_NAME,
};

namespace inputMode {
    enum InputMode {
        GAME_CONTROL,
        TEXT_INSERT,
    };
}


class Player : public Object, public EventEmitter<PlayerEventType> {
private:
    std::string playerInput;
    short horizontalMovement{0};
    sf::Sprite sprite;
    sf::Sprite backlight{};
    bool willJump = false;
    sf::Vector2f spawnPoint;
    TextureSwitcher<TextureId> animatedTxt;
    bool wKeyPressed{false};
    Camera const& camera;
    inputMode::InputMode inputMode{inputMode::GAME_CONTROL};

    std::shared_ptr<EntityModule> entityModule = std::make_shared<MortalEntityModule>(10, onDeath);

    auto onKeyPress(sf::Event event) -> void;
    auto onKeyRelease(sf::Event event) -> void;
    auto onButtonPress(sf::Event event) -> void;
    auto onTextEntered(sf::Event event) -> void;
    std::function<void()> onDeath = [this]() -> void {
        emit(DEATH);
        pos = spawnPoint;
    };
    auto setAnimationState() -> void;
    auto renderBacklight(sf::Vector2f const& screenPos, sf::RenderWindow *window) -> void;
public:
    explicit Player(InitContext ctx, std::string const& uid);

    auto isWKeyPressed() -> bool;

    auto dispatchEvents(sf::RenderWindow& window) -> void;
    auto setSpawnPoint() -> void;
    auto setInputMode(inputMode::InputMode newMode) -> void;
    auto getEnteredText() -> std::string;

    auto getBoundingBox() -> sf::FloatRect override;
    auto render(Context ctx) -> void override;
    void onBeforeStep(long long timeElapsed) override;

    void load(nlohmann::json const& json) override;
    std::unique_ptr<nlohmann::json> save() override;
};


#endif //PJC_PROJECT_PLAYER_H
