#ifndef WOLFMODEL_HPP
#define WOLFMODEL_HPP
#include "IAnimal.hpp"
#include <memory>

class Wolf : public IAnimal {
public:
  Wolf();
  std::string attack() override { return "The wolf attacks with his fangs !"; }
  std::shared_ptr<Monster> create() override;
  std::string getName() override { return "Wolf"; };
  //    virtual void move() = 0;
  //    virtual IBreed& clone() = 0;
};

#endif // WOLFMODEL_HPP
