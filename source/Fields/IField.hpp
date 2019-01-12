
#ifndef IFIELD_HPP
#define IFIELD_HPP

#include <cstdint>
#include <vector>
#include <iostream>
#include <memory>

// Preferably polimorphism mechanism will be used.

class IField {
private:
public:
    IField();
    IField(const IField& orig) = delete;
    virtual ~IField();

    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual void printField() = 0;
    virtual std::string getType() = 0;
    virtual std::ostream& operator<<(std::ostream& stream) = 0;
private:

};

#endif /* IFIELD_HPP */

