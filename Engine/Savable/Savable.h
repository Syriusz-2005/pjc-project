

#ifndef PJC_PROJECT_SAVABLE_H
#define PJC_PROJECT_SAVABLE_H
#include <nlohmann/json.hpp>


class Savable {
public:
    virtual auto load(nlohmann::json json) -> void = 0;
    virtual auto save() -> nlohmann::json = 0;
};


#endif //PJC_PROJECT_SAVABLE_H
