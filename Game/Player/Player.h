
#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "../../Engine/Group/Group.h"
#include "../../Engine/Rect/Rect.h"
#include "../InitContext/InitContext.h"
#include "../../Engine/MortalEntityModule/MortalEntityModule.h"

class Player : public Object {
private:
    short horizontalMovement = 0;
    sf::Sprite sprite;
    bool willJump = false;
    sf::Vector2f spawnPoint;
    std::shared_ptr<EntityModule> entityModule = std::make_shared<MortalEntityModule>(10, onDeath);

    auto onKeyPress(sf::Event event) -> void;
    auto onKeyRelease(sf::Event event) -> void;
    std::function<void()> onDeath = [this]() -> void {
        fmt::println("The player died");
        pos = spawnPoint;
    };
public:
    explicit Player(InitContext ctx, std::string uid);

    auto dispatchEvents(sf::RenderWindow& window) -> void;
    auto setSpawnPoint() -> void;

    auto getBoundingBox() -> sf::FloatRect override;
    auto render(Context ctx) -> void override;
    void onBeforeStep() override;

    void load(nlohmann::json const& json) override;
    std::unique_ptr<nlohmann::json> save() override;
};


#endif //PJC_PROJECT_PLAYER_H
