

#ifndef PJC_PROJECT_STATESTORE_H
#define PJC_PROJECT_STATESTORE_H

#include <map>

template <typename T>
class StateValue {
    T val{};
public:
    StateValue() = default;

    auto set(T v) -> void {
        val = v;
    }

    auto get() -> T {
        return val;
    }
};

template <typename T, typename V>
class StateStore {
    std::map<T, StateValue<V>> values{};

public:
    auto set(T key, V val) -> void {
        values[key].set(val);
    }

    auto get(T key) -> V {
        return values[key].get();
    }
};


#endif //PJC_PROJECT_STATESTORE_H
