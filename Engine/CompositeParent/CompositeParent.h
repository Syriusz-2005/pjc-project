//
// Created by NOWY on 30.04.2024.
//

#ifndef PJC_PROJECT_COMPOSITEPARENT_H
#define PJC_PROJECT_COMPOSITEPARENT_H


#include <memory>

template <typename T>
class CompositeParent {
public:
    virtual auto add(std::shared_ptr<T> o) -> void = 0;
    virtual auto remove(std::shared_ptr<T> o) -> void = 0;
    virtual auto remove(T* o) -> void = 0;
};


#endif //PJC_PROJECT_COMPOSITEPARENT_H
