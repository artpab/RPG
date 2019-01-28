#ifndef MONSTERGENERATOR_HPP
#define MONSTERGENERATOR_HPP

#include "../Fields/IField.hpp"
#include "Animals/Bear.hpp"
#include "Factories/AnimalFactory.hpp"
#include "Factories/IMonsterFactory.hpp"
#include "Monster.hpp"
#include <map>
#include <vector>

typedef std::vector<std::vector<std::shared_ptr<IField>>> worldVector;
typedef std::map<std::string, IBreed *> breedMap;

class MonsterGenerator {
public:
  MonsterGenerator();

  void registerBreed(const std::string &type, IMonsterFactory *factory) {
    factories.emplace(type, factory);
  }
  void createMonsters(worldVector &world_map);
  void createMonstersFactories();
  void createBreeds();

private:
  std::map<std::string, IMonsterFactory *> factories;
  std::vector<std::shared_ptr<Monster>> monsters;
  breedMap breeds;
};

#endif // MONSTERGENERATOR_HPP
