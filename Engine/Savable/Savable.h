

#ifndef PJC_PROJECT_SAVABLE_H
#define PJC_PROJECT_SAVABLE_H
#include <nlohmann/json.hpp>


class Savable {
public:
    virtual auto load(nlohmann::json const& json) -> void = 0;
    virtual auto save() -> std::unique_ptr<nlohmann::json> = 0;
    virtual auto isUidMatch(std::string& id) -> bool = 0;
};


#endif //PJC_PROJECT_SAVABLE_H
