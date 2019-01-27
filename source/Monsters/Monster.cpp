#include "Monster.hpp"

Monster::Monster(std::shared_ptr<IBreed> breed_ptr) : breed(breed_ptr) {}
Monster::Monster(int health) {}
