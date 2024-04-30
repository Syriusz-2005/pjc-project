
#include "MortalEntityModule.h"
#include "fmt/core.h"

MortalEntityModule::MortalEntityModule(float hp, std::function<void()> const& onDeath): hp(hp), onDeath(onDeath) {

}

void MortalEntityModule::damage(float val) {
    fmt::println("Mortal entity applying damage");
    hp -= val;
    if (hp <= 0) {
        onDeath();
    }
}
