#ifndef IBREED_HPP
#define IBREED_HPP

#include <iostream>


class IBreed
{
public:
    IBreed();
    virtual std::string attack() = 0;
//    virtual void move() = 0;
//    virtual IBreed& clone() = 0;
};

#endif // IBREED_HPP
