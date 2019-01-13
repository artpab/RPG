
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
    void printField() override;
    std::string getType() override;
    std::ostream& operator<<(std::ostream& stream) override;

    int getX() override {
        return _posX;
    }

    int getY() override {
        return _posY;
    }
private:
};

#endif /* FOREST_HPP */

