#include "AnimalFactory.hpp"

AnimalFactory::AnimalFactory() {}

std::shared_ptr<Monster> AnimalFactory::createMonster() {

  return std::make_shared<Monster>(std::make_shared<Wolf>());
}
