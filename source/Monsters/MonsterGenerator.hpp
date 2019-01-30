#ifndef MONSTERGENERATOR_HPP
#define MONSTERGENERATOR_HPP

#include "../Fields/IField.hpp"
#include "Animals/Bear.hpp"
#include "Animals/Wolf.hpp"
#include "Monster.hpp"
#include <map>
#include <vector>

typedef std::vector<std::vector<std::shared_ptr<IField>>> worldVector;
typedef std::vector<std::shared_ptr<IBreed>> breedVec;

class MonsterGenerator {
public:
  MonsterGenerator();
  void populateMap(worldVector &world_map);
  void createBreeds();

private:
  std::vector<std::shared_ptr<Monster>> monsters;
  breedVec breeds;
};

#endif // MONSTERGENERATOR_HPP
