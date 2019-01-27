#ifndef IMONSTER_HPP
#define IMONSTER_HPP

#include "IBreed.hpp"
#include "memory"

class Monster {
public:
  //    Monster(std::shared_ptr<IBreed> breed_ptr);
  Monster(int health);

protected:
  //    std::shared_ptr<IBreed> breed;
  int current_health;
  IBreed &breed;
};

#endif // IMONSTER_HPP
