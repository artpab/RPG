#ifndef ANIMALFACTORY_HPP
#define ANIMALFACTORY_HPP

#include "../Animals/IAnimal.hpp"
#include "../Animals/Wolf.hpp"
#include "../Monster.hpp"
#include "IMonsterFactory.hpp"
#include "memory"

class AnimalFactory : public IMonsterFactory {
public:
  AnimalFactory();
  std::shared_ptr<Monster> createMonster() override;
  std::shared_ptr<IAnimal> breed_ptr;
};

#endif // ANIMALFACTORY_HPP
