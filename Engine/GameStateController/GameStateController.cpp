
#include "GameStateController.h"
#include "fmt/core.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <utility>

GameStateController::GameStateController(Savable *savable, std::string fileLocation): savable(savable), fileLocation(std::move(fileLocation)) {

}

auto GameStateController::loadIfExists() -> void {
    auto file = std::ifstream(fileLocation);
    if (file) {
        nlohmann::json j;
        file >> j;
        savable->load(j);
        fmt::println("Game loaded!");
    }
    file.close();
}

auto GameStateController::saveToFile() -> void {
    auto file = std::ofstream(fileLocation);
    fmt::println("File opened");
    auto outJson = savable->save();
    fmt::println("JSON produced");
    file << *outJson;
    file.close();
}
