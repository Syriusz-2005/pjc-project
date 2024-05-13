
#ifndef PJC_PROJECT_GAMESTATECONTROLLER_H
#define PJC_PROJECT_GAMESTATECONTROLLER_H


#include "../Savable/Savable.h"

class GameStateController {
private:
    Savable* savable;
    std::string fileLocation;

    auto getLocation(const std::string & saveName) -> std::string;
public:
    explicit GameStateController(Savable* savable, std::string fileLocation);

    auto loadIfExists(std::string const& saveName) -> void;
    auto saveToFile(std::string const& saveName) -> void;
};


#endif //PJC_PROJECT_GAMESTATECONTROLLER_H
