

#include "TextField.h"

TextField::TextField(const std::string &uid, const int &focusedInputIdState, const int& textStateId): Button(uid, ""), focusedInputIdState(focusedInputIdState), textStateId(textStateId) {

}

void TextField::onBeforeStep(long long int timeElapsed) {
    Object::onBeforeStep(timeElapsed);
    auto state = parent->state.get(focusedInputIdState);
    if (std::holds_alternative<std::string>(state)) {
        auto focusedInputId = std::get<std::string>(state);
        if (focusedInputId == getUid()) {
            auto textState = parent->state.get(textStateId);
            if (not std::holds_alternative<std::string>(textState)) return;
            auto textValue = std::get<std::string>(textState);
            setText(textValue);
        }
    }
}
