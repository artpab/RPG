#ifndef IBREED_HPP
#define IBREED_HPP

#include "Monster.hpp"
#include <iostream>
#include <memory>

class Monster;

class IBreed : public std::enable_shared_from_this<IBreed> {
public:
  IBreed();
  virtual std::string attack() = 0;
  virtual std::shared_ptr<Monster> create() = 0;
  virtual std::string getName() = 0;
  virtual ~IBreed(){};
  int maxHealth;
  //    virtual void move() = 0;
  //    virtual IBreed& clone() = 0;
};

#endif // IBREED_HPP
