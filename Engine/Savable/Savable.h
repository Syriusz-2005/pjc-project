

#ifndef PJC_PROJECT_SAVABLE_H
#define PJC_PROJECT_SAVABLE_H
#include <nlohmann/json.hpp>


class Savable {
public:
    bool isSavable{true};

    virtual auto load(nlohmann::json const& json) -> void = 0;
    virtual auto save() -> std::unique_ptr<nlohmann::json> = 0;
    virtual auto isUidMatch(std::string const& id) const -> bool = 0;
};


#endif //PJC_PROJECT_SAVABLE_H
