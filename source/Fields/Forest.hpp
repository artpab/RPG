
#ifndef FOREST_HPP
#define FOREST_HPP
#include "IField.hpp"
#include "TerrainModels/ForestModel.hpp"

class Forest : public IField {
private:
    int _posX, _posY;
public:
    Forest(int X, int Y, std::shared_ptr<ITerrainModel> ptr);
    virtual ~Forest();
    std::string getType() override;

    int getX() override {
        return _posX;
    }

    int getY() override {
        return _posY;
    }
    std::string printField() override {return "#"; }
    std::shared_ptr<ITerrainModel> getModelPtr() override {return _model_ptr;}

private:
};

#endif /* FOREST_HPP */

