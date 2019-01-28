#ifndef BEAR_HPP
#define BEAR_HPP
#include "../Factories/AnimalFactory.hpp"
#include "IAnimal.hpp"

class Bear : public IAnimal {
public:
  Bear();
  std::string attack() override { return "The bear attacks with his fangs !"; }
  AnimalFactory *factory_ptr;
};

#endif // BEAR_HPP
