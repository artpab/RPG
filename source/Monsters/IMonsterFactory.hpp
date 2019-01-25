#ifndef IMONSTERFACTORY_HPP
#define IMONSTERFACTORY_HPP

#include "IMonster.hpp"
#include "memory"

class IMonsterFactory
{
public:
    IMonsterFactory();
    virtual std::shared_ptr<IMonster> create() =0 ;
};

#endif // IMONSTERFACTORY_HPP
