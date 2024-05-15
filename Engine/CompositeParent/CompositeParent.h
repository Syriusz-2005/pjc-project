

#ifndef PJC_PROJECT_COMPOSITEPARENT_H
#define PJC_PROJECT_COMPOSITEPARENT_H


#include <memory>
#include <vector>
#include <functional>
#include <variant>
#include "../StateStore/StateStore.h"

template <typename T, typename K>
class CompositeParent {
public:
    StateStore<K, std::variant<bool, std::string>> state{};


    virtual auto add(std::shared_ptr<T> o) -> void = 0;
    virtual auto remove(std::shared_ptr<T> o) -> void = 0;
    virtual auto remove(std::string const& uid) -> void = 0;
    virtual auto getChildren() -> std::vector<std::shared_ptr<T>> const& = 0;
    virtual auto getChildren(std::function<bool(T&)> const& predicate) -> std::vector<std::shared_ptr<T>> const& = 0;
    virtual auto forEach(std::vector<std::string> const& uids, std::function<void(T&)> callback) -> void = 0;
};


#endif //PJC_PROJECT_COMPOSITEPARENT_H
