/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.cpp
 * Author: goti
 * 
 * Created on January 6, 2019, 12:11 PM
 */

#include "MapController.hpp"
#include "memory"
//#include "source/Fields/Plains.hpp"


Map::Map() : chance_vec{34, 33, 33}
{

}

Map::Map(std::vector<int> chance_vec) : chance_vec(chance_vec) {
}

Map::~Map() {
}

void Map::create_map(const std::pair<int,int>& dimensions, const std::vector<int>& chance_vec) {
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
            field_map[id]->printField();
            ++id;
        }
        std::cout << "\n";
    }
}