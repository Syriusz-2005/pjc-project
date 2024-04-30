
#include "MortalEntityModule.h"
#include "fmt/core.h"

MortalEntityModule::MortalEntityModule(float hp, std::function<void()> const& onDeath): hp(hp), onDeath(onDeath) {

}

void MortalEntityModule::damage(float val) {
    hp -= val;
    if (hp <= 0) {
        onDeath();
    }
}
