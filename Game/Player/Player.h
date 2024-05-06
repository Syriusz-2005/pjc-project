
#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "../../Engine/Group/Group.h"
#include "../../Engine/Rect/Rect.h"
#include "../InitContext/InitContext.h"
#include "../../Engine/MortalEntityModule/MortalEntityModule.h"
#include "../../Engine/EventEmitter/EventEmitter.h"
#include "../../Engine/TextureSwitcher/TextureSwitcher.h"

enum PlayerEventType {
        DEATH,
};


class Player : public Object, public EventEmitter<PlayerEventType> {
private:
    short horizontalMovement{0};
    sf::Sprite sprite;
    sf::Sprite backlight{};
    bool willJump = false;
    sf::Vector2f spawnPoint;
    TextureSwitcher<TextureId> animatedTxt;
    bool wKeyPressed{false};

    std::shared_ptr<EntityModule> entityModule = std::make_shared<MortalEntityModule>(10, onDeath);

    auto onKeyPress(sf::Event event) -> void;
    auto onKeyRelease(sf::Event event) -> void;
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

    auto getBoundingBox() -> sf::FloatRect override;
    auto render(Context ctx) -> void override;
    void onBeforeStep() override;

    void load(nlohmann::json const& json) override;
    std::unique_ptr<nlohmann::json> save() override;
};


#endif //PJC_PROJECT_PLAYER_H
