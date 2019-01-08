
#include "MapController.hpp"
#include "memory"


MapController::MapController() : chance_vec{34, 33, 33}
{

}

MapController::MapController(std::vector<int> chance_vec) : chance_vec(chance_vec) {
}

MapController::~MapController() {
}

void MapController::create_map(const std::pair<int,int>& dimensions, const std::vector<int>& chance_vec) {
    int id = 0;
    srand(time(NULL));
    for (int i = 0; i < dimensions.first; ++i) {
        for (int j = 0; j < dimensions.second; ++j) {
            int prob = rand() % 101;
            if (prob <= chance_vec[static_cast<int> (FieldTypes::fields_chance)]) {
                auto field_ptr = std::make_shared<Plains>(i, j);
                field_map.emplace(id,field_ptr);
            } else if ((prob > chance_vec[static_cast<int> (FieldTypes::fields_chance)]) && (prob < (chance_vec[static_cast<int>(FieldTypes::fields_chance)] + chance_vec[static_cast<int> (FieldTypes::woods_chance)]))) {
                auto field_ptr = std::make_shared<Forest>(i, j);
                field_map.emplace(id,field_ptr);
            } else {
                auto field_ptr = std::make_shared<Water>(i, j);
                field_map.emplace(id,field_ptr);
            }
            ++id;
        }
        std::cout << "\n";
    }
}

void MapController::save_map()
{
        ptr_MapWriter = std::make_shared<MapWriter>();
        ptr_MapWriter->writeMap(field_map);
}

void MapController::load_map()
{
    ptr_MapReader = std::make_shared<MapReader>();
    ptr_MapReader->loadMapfromXML(field_map);
}

void MapController::print_map()
{
    for (auto& element:field_map)
    {
        element.second->printField();
    }
    
}