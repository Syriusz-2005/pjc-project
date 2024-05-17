
#include "GameStateController.h"
#include "fmt/core.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <utility>
#include <filesystem>

GameStateController::GameStateController(Savable *savable, std::string fileLocation): savable(savable), fileLocation(std::move(fileLocation)) {

}

auto GameStateController::getLocation(const std::string &saveName) -> std::string {
    return fileLocation + saveName + ".splash.json";
}

//Source: https://github.com/nlohmann/json
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

auto GameStateController::listSaveNames() -> std::unique_ptr<std::vector<std::string>> {
    namespace fs = std::filesystem;
    auto saves = std::make_unique<std::vector<std::string>>();
    auto ext = std::string{".splash.json"};
    for (auto& entry : fs::directory_iterator(fileLocation)) {
        auto filename = entry.path().filename().string();
        if (filename.ends_with(ext)) {
            // Source for str replacing in c++: https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
            auto pos = filename.find(ext);
            if (pos == std::string::npos) continue;
            auto saveName = filename.replace(pos, ext.size(), "");
            fmt::println("Save file: {}", saveName);
            saves->push_back(saveName);
        }
    }
    return saves;
}

