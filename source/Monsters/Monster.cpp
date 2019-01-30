#include "Monster.hpp"

Monster::Monster(const std::shared_ptr<IBreed> breed_ptr) : breed(breed_ptr) {
  current_health = breed->maxHealth;
}
