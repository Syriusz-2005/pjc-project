
#ifndef PJC_PROJECT_TEXTDISPLAY_H
#define PJC_PROJECT_TEXTDISPLAY_H


#include "../Object/Object.h"

class TextDisplay : public Object {
    std::string text;
public:
    explicit TextDisplay(std::string const& uid, std::string const& text);

    void render(Context ctx) override;
    sf::FloatRect getBoundingBox() override;
};


#endif //PJC_PROJECT_TEXTDISPLAY_H
