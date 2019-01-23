#include "Plains.hpp"

Plains::Plains(int X, int Y, std::shared_ptr<ITerrainModel> ptr):_posX(X),_posY(Y), _model_ptr(ptr){}

Plains::~Plains() {
}

std::string Plains::getType()
{
    return "Plains";
}
