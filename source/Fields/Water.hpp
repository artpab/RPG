

#ifndef WATER_HPP
#define WATER_HPP
#include "IField.hpp"
#include "TerrainModels/WaterModel.hpp"

class Water : public IField {
private:
    int _posX, _posY;
        std::shared_ptr<ITerrainModel> _model_ptr = nullptr;
public:
    Water(int X, int Y, std::shared_ptr<ITerrainModel> ptr);
    Water(const Water& orig);
    virtual ~Water();
    void printField() override;
    std::string getType() override;
    std::ostream& operator<<(std::ostream& stream) override;

    int getX() override {
        return _posX;
    }

    int getY() override {
        return _posY;
    }

};

#endif /* WATER_HPP */

