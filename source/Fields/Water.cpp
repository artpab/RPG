#include "Water.hpp"

Water::Water(int X, int Y, std::shared_ptr<ITerrainModel> ptr) :_posX(X),_posY(Y){
_model_ptr = ptr;
}


Water::~Water() {
}

std::string Water::getType()
{
    return "Water";
}
