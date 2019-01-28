#ifndef WOLFMODEL_HPP
#define WOLFMODEL_HPP
#include "../Factories/AnimalFactory.hpp"
#include "IAnimal.hpp"

class Wolf : public IAnimal {
public:
  Wolf();
  std::string attack() override { return "The wolf attacks with his fangs !"; }
  AnimalFactory *factory_ptr;
  //    virtual void move() = 0;
  //    virtual IBreed& clone() = 0;
};

#endif // WOLFMODEL_HPP
