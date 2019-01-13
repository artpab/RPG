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
#include "../Fields/IField.hpp"
#include "../Fields/TerrainModels/ITerrainModel.hpp"
#include "../Fields/Forest.hpp"
#include "../Fields/Water.hpp"
#include "../Fields/Plains.hpp"
#include "../MapIO/MapWriter.hpp"
#include "../MapIO/MapReader.hpp"
#include "Builders/FieldBuilder.hpp"
#include "Display/Display.hpp"
#include <iostream>
#include <ctime>
#include <vector>

enum class FieldTypes {
    fields_chance, woods_chance, water_chance
};

typename std::vector<std::vector<std::shared_ptr<IField>>> worldVector;

class MapController {
public:
    MapController();
    MapController(std::vector<int> chance_vec);
    virtual ~MapController();
    void create_map(const std::pair<int, int>&);
    void save_map();
    void load_map();
    void load_map_from_XML(std::shared_ptr<MapReader>, std::map<int, std::shared_ptr<IField>>&);
    void print_map();
    void displayFieldInfo(std::pair<int,int>);
    int getSizeX(){return _sizeX;};
    int getSizeY(){return _sizeY;};


private:
    worldVector _worldMap;
    std::vector<int> _chance_vec;
    std::shared_ptr<MapWriter> _pMapWriter ;
    std::shared_ptr<MapReader> _pMapReader ;
    std::shared_ptr<FieldBuilder> _pBuilder;
    std::shared_ptr<Display> _pDisplay;
    int _sizeX, _sizeY;
    
    

};

#endif /* MAPCONTROLLER_HPP */

