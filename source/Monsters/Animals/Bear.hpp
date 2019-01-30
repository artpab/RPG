#ifndef BEAR_HPP
#define BEAR_HPP
#include "IAnimal.hpp"

class Bear : public IAnimal {
public:
  Bear();
  std::string attack() override { return "The bear attacks with his fangs !"; }
  std::shared_ptr<Monster> create() override;
  std::string getName() override { return "Bear"; };

private:
};

#endif // BEAR_HPP
