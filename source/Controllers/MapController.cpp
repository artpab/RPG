
#include "MapController.hpp"
#include "memory"


MapController::MapController() : _chance_vec{70, 20, 10}
{
    _pBuilder = std::make_shared<FieldBuilder>();
    _pDisplay = std::make_shared<Display>();
}

MapController::MapController(std::vector<int> chance_vec) : _chance_vec(chance_vec) {
    _pBuilder = std::make_shared<FieldBuilder>();
    _pDisplay = std::make_shared<Display>();
}

MapController::~MapController() {
}

void MapController::create_map(const std::pair<int, int>& dimensions) {
    srand(time(NULL));
    _sizeX = dimensions.first;
    _sizeY = dimensions.second;
    for (int i = 0; i < _sizeX; ++i) {
        for (int j = 0; j<_sizeY; ++j) {
            int prob = rand() % 101;
            if (prob <= _chance_vec[static_cast<int> (FieldTypes::fields_chance)]) {
                auto field_ptr = _pBuilder->createPlains(i, j);
                std::cout<<field_ptr->getType()<<" ";
                _worldMap[i].push_back(field_ptr);
 
            } else if ((prob > _chance_vec[static_cast<int> (FieldTypes::fields_chance)]) && (prob < (_chance_vec[static_cast<int> (FieldTypes::fields_chance)] + _chance_vec[static_cast<int> (FieldTypes::woods_chance)]))) {
                auto field_ptr = _pBuilder-> createForest(i, j);
                std::cout<<field_ptr->getType()<<" ";
                _worldMap[i].push_back(field_ptr);
            } else {
                auto field_ptr = _pBuilder->createWater(i, j);
                std::cout<<field_ptr->getType()<<" ";
                _worldMap[i].push_back(field_ptr);
            }
//            std::cout<<field_ptr->getType()<<" ";
        }
        std::cout << "\n";
    }
}

void MapController::save_map() {
    _pMapWriter = std::make_shared<MapWriter>();
    _pMapWriter->writeMap(_worldMap);
}

void MapController::load_map() {
    _pMapReader = std::make_shared<MapReader>(_pBuilder);
    _pMapReader->loadMapfromXML(std::make_pair(_sizeX,_sizeY),_worldMap);
}

void MapController::print_map() {
//    for (auto& element : _worldMap) {
//        element.second->printField();
//    }
}

void MapController::displayFieldInfo(std::pair<int,int> field)
{
//    _pDisplay->displayInfo(field, _worldMap);
}