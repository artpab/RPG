#ifndef IMONSTERFACTORY_HPP
#define IMONSTERFACTORY_HPP

#include "Animals/Wolf.hpp"
#include "Monster.hpp"
#include "memory"

class IMonsterFactory {
public:
  IMonsterFactory();
  //    virtual std::shared_ptr<Monster> create() =0 ;
  std::shared_ptr<Monster> create();
  void populate();
  //  std::shared_ptr<IBreed> breed_ptr;
};

#endif // IMONSTERFACTORY_HPP
