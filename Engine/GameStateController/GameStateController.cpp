
#include "GameStateController.h"
#include <fstream>
#include <nlohmann/json.hpp>

GameStateController::GameStateController(Savable *savable, std::string fileLocation): savable(savable), fileLocation(fileLocation) {

}

auto GameStateController::loadIfExists() -> void {
    auto file = std::ifstream(fileLocation);
    if (file) {
        nlohmann::json j;
        file >> j;
        savable->load(j);
    }
    file.close();
}

auto GameStateController::saveToFile() -> void {
    auto file = std::ofstream(fileLocation);
    auto outJson = savable->save();
    file << outJson;
}
