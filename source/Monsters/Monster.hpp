#ifndef IMONSTER_HPP
#define IMONSTER_HPP

#include "IBreed.hpp"
#include "memory"

class Monster {
public:
  Monster(std::shared_ptr<IBreed> breed_ptr);

protected:
  std::shared_ptr<IBreed> breed;
  int current_health = 100;
  //  IBreed &breed;
};

#endif // IMONSTER_HPP
