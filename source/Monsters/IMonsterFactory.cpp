#include "IMonsterFactory.hpp"

IMonsterFactory::IMonsterFactory() {}

std::shared_ptr<Monster> IMonsterFactory::create() {
  auto wolf_ptr = std::make_shared<Wolf>();
  return std::make_shared<Monster>(wolf_ptr);
}
void IMonsterFactory::populate() {

  for (int i = 0; i < 4; i++) {
    create();
  }
}
