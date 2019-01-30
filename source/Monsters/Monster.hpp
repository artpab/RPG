#ifndef IMONSTER_HPP
#define IMONSTER_HPP

#include "IBreed.hpp"
#include "memory"

class IBreed;

class Monster {
public:
  Monster(std::shared_ptr<IBreed> breed_ptr);
  int getCurrentHealth() { return current_health; }
  std::shared_ptr<IBreed> getBreedPtr() { return breed; }

private:
  int current_health;
  std::shared_ptr<IBreed> breed;
};

#endif // IMONSTER_HPP
