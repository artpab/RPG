
#include "MapController.hpp"
#include "memory"


MapController::MapController() : _chance_vec{34, 33, 33}
{

}

MapController::MapController(std::vector<int> chance_vec) : _chance_vec(chance_vec) {
}

MapController::~MapController() {
}

void MapController::create_map(const std::pair<int, int>& dimensions, const std::vector<int>& chance_vec) {
    int id = 0;
    srand(time(NULL));
    for (int i = 0; i < dimensions.first; ++i) {
        for (int j = 0; j < dimensions.second; ++j) {
            int prob = rand() % 101;
            if (prob <= chance_vec[static_cast<int> (FieldTypes::fields_chance)]) {
                auto field_ptr = std::make_shared<Plains>(i, j,_ptr_PModel);
                _field_map.emplace(id, field_ptr);
            } else if ((prob > chance_vec[static_cast<int> (FieldTypes::fields_chance)]) && (prob < (chance_vec[static_cast<int> (FieldTypes::fields_chance)] + chance_vec[static_cast<int> (FieldTypes::woods_chance)]))) {
                auto field_ptr = std::make_shared<Forest>(i, j,_ptr_FModel);
                _field_map.emplace(id, field_ptr);
            } else {
                auto field_ptr = std::make_shared<Water>(i, j, _ptr_WModel);
                _field_map.emplace(id, field_ptr);
            }
            ++id;
        }
        std::cout << "\n";
    }
}

void MapController::save_map() {
    _ptr_MapWriter = std::make_shared<MapWriter>();
    _ptr_MapWriter->writeMap(_field_map);
}

void MapController::load_map() {
    _ptr_MapReader = std::make_shared<MapReader>();
    _ptr_MapReader->loadMapfromXML(_field_map);
}

void MapController::print_map() {
    for (auto& element : _field_map) {
        element.second->printField();
    }
}

void MapController::create_models()
{

}