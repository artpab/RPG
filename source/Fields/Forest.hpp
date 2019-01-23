
#ifndef FOREST_HPP
#define FOREST_HPP
#include "IField.hpp"
#include "TerrainModels/ForestModel.hpp"

class Forest : public IField {
private:
    int _posX, _posY;
    std::shared_ptr<ITerrainModel> _model_ptr = nullptr;
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
        auto getModelptr() {return _model_ptr;}
private:
};

#endif /* FOREST_HPP */

