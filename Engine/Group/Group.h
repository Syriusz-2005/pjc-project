
#ifndef PJC_PROJECT_GROUP_H
#define PJC_PROJECT_GROUP_H

#include "../Object/Object.h"

class Group : public Object {
private:
    std::vector<Object*> objects{std::vector<Object*>()};
    sf::FloatRect const* area;
public:
    explicit Group(const PhysicsModule * module, Layer layer);

    auto add(Object& o) -> void;
    auto render(Context ctx) -> void override;
    auto getBoundingBox() -> sf::FloatRect override;
    auto getObjects() -> std::vector<Object*> const&;

    auto setBoundingBox(sf::FloatRect const& box) -> void;
};


#endif //PJC_PROJECT_GROUP_H
