#include "MonsterGenerator.hpp"

MonsterGenerator::MonsterGenerator() {}

void MonsterGenerator::populateMap(worldVector &world_map) {
  createBreeds();
  int x = world_map.size();
  int y = world_map[0].size();
  int worldSize = x * y;
  for (int i = 0; i < worldSize / 2; ++i) {
    if (i & 1)
      monsters.push_back(breeds[0]->create());
    else
      monsters.push_back(breeds[1]->create());
  }

  for (auto &monster : monsters) {
    int temp_x = rand() % x;
    int temp_y = rand() % y;
    if (!world_map[temp_x][temp_y]->monsterAvailable()) {
      world_map[temp_x][temp_y]->assignMonster(monster);
      //      std::cout << "Spawning " << monster->getBreedPtr()->getName()
      //                << " at location [" << temp_x << "," << temp_y << "]\n";
    } else {
      //      std::cout << "Cannot spawn monster at location [" << temp_x << ","
      //                << temp_y << "]\n";
    }
  }
}

void MonsterGenerator::createBreeds() {

  breeds.push_back(std::make_shared<Wolf>());
  breeds.push_back(std::make_shared<Bear>());
}
