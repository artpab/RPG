
#ifndef IFIELD_HPP
#define IFIELD_HPP

#include <cstdint>
#include <vector>
#include <iostream>
#include <memory>
#include "TerrainModels/ITerrainModel.hpp"

// Preferably polimorphism mechanism will be used.

class IField {
protected:
    std::shared_ptr<ITerrainModel> _model_ptr = nullptr;
    bool containsMonster = false;
public:
    IField();
//    IField(std::shared_ptr<ITerrainModel>);
    IField(const IField& orig) = delete;
    virtual ~IField();    
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual std::string printField() = 0;
    virtual std::string getType() = 0;
    virtual std::shared_ptr<ITerrainModel> getModelPtr() = 0;
    virtual void provideData = 0;
    
private:

};

#endif /* IFIELD_HPP */

