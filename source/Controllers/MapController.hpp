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

#ifndef MAPCONTROLLER_HPP
#define MAPCONTROLLER_HPP
#include <map>
#include <memory>
#include "../Fields/Field.hpp"
#include "../Fields/Forest.hpp"
#include "../Fields/Water.hpp"
#include "../Fields/Plains.hpp"
#include "../MapIO/MapWriter.hpp"
#include "../MapIO/MapReader.hpp"
#include <iostream>
#include <ctime>

enum class FieldTypes
{
    fields_chance, woods_chance, water_chance
};


class MapController{
public:
    MapController();
    MapController(std::vector<int> chance_vec);
    virtual ~MapController();
    void create_map(const std::pair<int,int>& , const std::vector<int>&);
    void save_map();
    void load_map();
    void load_map_from_XML(std::shared_ptr<MapReader>, std::map<int, std::shared_ptr<Field>>&);
    void print_map();
    
private:
std::map<int, std::shared_ptr<Field>> field_map;
std::vector<int> chance_vec;
std::shared_ptr<MapWriter> ptr_MapWriter = nullptr;
std::shared_ptr<MapReader> ptr_MapReader = nullptr;

};

#endif /* MAPCONTROLLER_HPP */

