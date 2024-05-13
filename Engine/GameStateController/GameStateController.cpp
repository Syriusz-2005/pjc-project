
#include "GameStateController.h"
#include "fmt/core.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <utility>

GameStateController::GameStateController(Savable *savable, std::string fileLocation): savable(savable), fileLocation(std::move(fileLocation)) {

}

auto GameStateController::getLocation(const std::string &saveName) -> std::string {
    return fileLocation + saveName + ".splash.json";
}

auto GameStateController::loadIfExists(std::string const& saveName) -> void {
    auto file = std::ifstream(getLocation(saveName));
    if (file) {
        nlohmann::json j;
        file >> j;
        savable->load(j);
        fmt::println("Game loaded!");
    }
    file.close();
}

auto GameStateController::saveToFile(std::string const& saveName) -> void {
    if (saveName.size() == 0) return;
    auto file = std::ofstream(getLocation(saveName));
    fmt::println("File opened");
    auto outJson = savable->save();
    fmt::println("JSON produced");
    file << *outJson;
    file.close();
}

