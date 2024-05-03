

#ifndef PJC_PROJECT_EVENTEMITTER_H
#define PJC_PROJECT_EVENTEMITTER_H

#include <functional>
#include <memory>
#include "fmt/core.h"

template <typename T>
class EventListener {
public:
    T event;
    bool isMicrotask;
    int microtaskCalls{0};
    std::function<void()> const& callback;
    EventListener(T event, std::function<void()> const& callback, bool isMicrotask = false): event(event), callback(callback), isMicrotask(isMicrotask) {

    }
    auto call() -> void {
        if (isMicrotask) {
            microtaskCalls++;
            return;
        }
        callback();
    }
    auto callMicrotask() -> void {
        for (int i = 0; i < microtaskCalls; i++) {
            callback();
        }
        microtaskCalls = 0;
    }
};


/**
 * Based on nodejs-style event emitters
 * The idea of "Microtasks" comes from nodejs too.
 * They're executed after all tasks in the game loop have been done
 * @tparam T
 */
template <typename T>
class EventEmitter {
    std::vector<std::unique_ptr<EventListener<T>>> listeners{};
protected:
    auto emit(T e) -> void {
        for (auto const& listener : listeners) {
            if (listener->event == e) {
                listener->call();
            }
        }
    }

    auto emitScheduledMicrotasks() -> void {
        for (auto const& listener : listeners) {
            listener->callMicrotask();
        }
    }

public:
    EventEmitter() = default;
    auto onMicrotask(T type, std::function<void()> const& callback) -> void {
        listeners.push_back(std::make_unique<EventListener<T>>(type, callback, true));
    }

    auto on(T type, std::function<void()> const& callback) -> void {
        listeners.push_back(std::make_unique<EventListener<T>>(type, callback));
    }

    auto off(T type, std::function<void()> const& callback) -> void {
        std::remove_if(listeners, [type, callback](std::unique_ptr<EventListener<T>> e) -> bool {
            return type == e->event and e->callback == callback;
        });
        listeners.erase();
    }
};


#endif //PJC_PROJECT_EVENTEMITTER_H
