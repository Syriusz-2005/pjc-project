
#ifndef PJC_PROJECT_GAMESTATECONTROLLER_H
#define PJC_PROJECT_GAMESTATECONTROLLER_H


#include "../Savable/Savable.h"

class GameStateController {
private:
    Savable* savable;
    std::string fileLocation;
public:
    explicit GameStateController(Savable* savable, std::string fileLocation);

    auto loadIfExists() -> void;
    auto saveToFile() -> void;
};


#endif //PJC_PROJECT_GAMESTATECONTROLLER_H
