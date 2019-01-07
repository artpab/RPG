/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.hpp
 * Author: goti
 *
 * Created on January 6, 2019, 12:11 PM
 */

#ifndef MAP_HPP
#define MAP_HPP
#include <map>
#include <memory>
#include "../Fields/Field.hpp"
#include "../Fields/Forest.hpp"
#include "../Fields/Water.hpp"
#include "../Fields/Plains.hpp"
#include <iostream>
#include <ctime>

enum class FieldTypes
{
    fields_chance, woods_chance, water_chance
};

class Map {
public:
    Map();
    Map(std::vector<int> chance_vec);
    virtual ~Map();
    void create_map(const std::vector<int>& chance_vec);
    
private:
std::map<int, std::shared_ptr<Field>> field_map;
std::vector<int> chance_vec;
};

#endif /* MAP_HPP */

