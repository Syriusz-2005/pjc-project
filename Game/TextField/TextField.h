
#ifndef PJC_PROJECT_TEXTFIELD_H
#define PJC_PROJECT_TEXTFIELD_H


#include "../Button/Button.h"

class TextField : public Button {
    int focusedInputIdState;
    int textStateId;
public:
    explicit TextField(const std::string &uid, int const& focusedInputIdState, const int& textStateId);

    void onBeforeStep(long long timeElapsed) override;
};


#endif //PJC_PROJECT_TEXTFIELD_H
