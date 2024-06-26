
#ifndef PJC_PROJECT_GROUP_H
#define PJC_PROJECT_GROUP_H

#include "../Object/Object.h"

class Group : public Object {
private:
    std::vector<Object*> objects{std::vector<Object*>()};
    sf::FloatRect const* area;
public:
    explicit Group(PhysicsModule &module, std::string uid, Layer layer);

    auto add(Object& o) -> void;
    auto render(Context ctx) -> void override;
    auto getBoundingBox() -> sf::FloatRect override;
    auto getObjects() -> std::vector<Object*> const&;

    auto setBoundingBox(sf::FloatRect const& box) -> void;

    ~Group() override;
};


#endif //PJC_PROJECT_GROUP_H
