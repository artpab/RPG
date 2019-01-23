
#include "Forest.hpp"

Forest::Forest(int X, int Y, std::shared_ptr<ITerrainModel> ptr) : IField(), _posX(X), _posY(Y), _model_ptr(ptr){
}

Forest::~Forest() {
}

//std::ostream& Forest::operator<<(std::ostream& stream) {
//    stream << "#";
//    return stream;
//}
std::string Forest::getType()
{
    return "Forest";
}
