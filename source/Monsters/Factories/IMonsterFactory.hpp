#ifndef IMONSTERFACTORY_HPP
#define IMONSTERFACTORY_HPP

#include "../Monster.hpp"
#include "memory"

class IMonsterFactory {
public:
  IMonsterFactory();
  //    virtual std::shared_ptr<Monster> create() =0 ;
  virtual std::shared_ptr<Monster> createMonster() = 0;
  void populate();
  std::shared_ptr<IBreed> breed_ptr;
};

#endif // IMONSTERFACTORY_HPP
