
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
    _rows = dimensions.first;
    _columns = dimensions.second;
    //    initializeMap(_worldMap);
    //    for (int i = 0; i < _sizeX; ++i) {
    //        for (int j = 0; j < _sizeY; ++j) {
    //            int prob = rand() % 101;
    //            if (prob <= _chance_vec[static_cast<int> (FieldTypes::fields_chance)]) {
    //                auto field_ptr = _pBuilder->createPlains(i, j);
    //                std::cout << field_ptr->getType() << " ";
    //                _worldMap[i].push_back(field_ptr);
    //
    //            } else if ((prob > _chance_vec[static_cast<int> (FieldTypes::fields_chance)]) && (prob < (_chance_vec[static_cast<int> (FieldTypes::fields_chance)] + _chance_vec[static_cast<int> (FieldTypes::woods_chance)]))) {
    //                auto field_ptr = _pBuilder-> createForest(i, j);
    //                std::cout << field_ptr->getType() << " ";
    //                _worldMap[i].push_back(field_ptr);
    //            } else {
    //                auto field_ptr = _pBuilder->createWater(i, j);
    //                std::cout << field_ptr->getType() << " ";
    //                _worldMap[i].push_back(field_ptr);
    //            }
    //        }
    //        std::cout << "\n";
    //    }

    for (int i = 0; i < _rows; ++i) {
        std::vector<std::shared_ptr < IField>> vec;
        for (int j = 0; j < _columns; ++j) {
            int prob = rand() % 101;

            if (prob <= _chance_vec[static_cast<int> (FieldTypes::fields_chance)]) {
                auto field_ptr = _pBuilder->createPlains(i, j);
                vec.push_back(field_ptr);
                std::cout << field_ptr->getType() << " ";

            } else if ((prob > _chance_vec[static_cast<int> (FieldTypes::fields_chance)]) && (prob < (_chance_vec[static_cast<int> (FieldTypes::fields_chance)] + _chance_vec[static_cast<int> (FieldTypes::woods_chance)]))) {
                auto field_ptr = _pBuilder-> createForest(i, j);
                vec.push_back(field_ptr);
                std::cout << field_ptr->getType() << " ";
            } else {
                auto field_ptr = _pBuilder->createWater(i, j);
                vec.push_back(field_ptr);
                std::cout << field_ptr->getType() << " ";
            }
        }
        _worldMap.push_back(vec);
        std::cout << "\n";
    }
}

void MapController::save_map() {
    _pMapWriter = std::make_shared<MapWriter>();
    _pMapWriter->writeMap(_worldMap);
}

void MapController::load_map() {
    _pMapReader = std::make_shared<MapReader>(_pBuilder);
    _pMapReader->loadMapfromXML(std::make_pair(_rows, _columns), _worldMap);
}

void MapController::print_map() {
    //    for (auto& element : _worldMap) {
    //        element.second->printField();
    //    }
}

void MapController::displayFieldInfo(std::pair<int, int> field) {
    //    _pDisplay->displayInfo(field, _worldMap);
}

void MapController::initializeMap(worldVector& _worldMap) {
    std::vector<std::shared_ptr < IField >> vec1(_columns, nullptr);
    worldVector vec2(_rows, vec1);
    _worldMap = vec2;
}