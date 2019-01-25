

#ifndef WATER_HPP
#define WATER_HPP
#include "IField.hpp"
#include "TerrainModels/WaterModel.hpp"

class Water : public IField {
private:
    int _posX, _posY;
public:
    Water(int X, int Y, std::shared_ptr<ITerrainModel> ptr);
    Water(const Water& orig);
    virtual ~Water();
    std::string getType() override;
    std::string printField() override {return "~"; }


    int getX() override {
        return _posX;
    }

    int getY() override {
        return _posY;
    }
        std::shared_ptr<ITerrainModel> getModelPtr() override {return _model_ptr;}

};

#endif /* WATER_HPP */

