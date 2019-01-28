#include "MonsterGenerator.hpp"

MonsterGenerator::MonsterGenerator() {}

void MonsterGenerator::createMonsters(worldVector &world_map) {

  auto monster_ptr = MonsterGenerator::factories["Wolf"]->createMonster();
  world_map[1][1]->assignMonster(monster_ptr);
  monsters.push_back(monster_ptr);
  monster_ptr = MonsterGenerator::factories["Bear"]->createMonster();
  world_map[2][2]->assignMonster(monster_ptr);
  monsters.push_back(monster_ptr);
}

void MonsterGenerator::createMonstersList() {
  registerBreed("Wolf", new AnimalFactory());
  registerBreed("Bear", new AnimalFactory());
}
