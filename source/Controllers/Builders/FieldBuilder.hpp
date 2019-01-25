/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FieldBuilder.hpp
 * Author: goti
 *
 * Created on January 13, 2019, 1:54 PM
 */

#ifndef FIELDBUILDER_HPP
#define FIELDBUILDER_HPP
#include "../../Fields/IField.hpp"
#include "../../Fields/Plains.hpp"
#include "../../Fields/Forest.hpp"
#include "../../Fields/Water.hpp"
#include "../../Fields/TerrainModels/ITerrainModel.hpp"
#include "../../Fields/TerrainModels/ForestModel.hpp"
#include "../../Fields/TerrainModels/PlainsModel.hpp"
#include "../../Fields/TerrainModels/WaterModel.hpp"
#include "memory"
#include "map"

class FieldBuilder {
public:
    FieldBuilder();
    virtual ~FieldBuilder();
    std::shared_ptr<Plains> createPlains(int, int);
    std::shared_ptr<Water> createWater(int,int);
    std::shared_ptr<Forest> createForest(int,int);
    
private:
    void create_models();
    std::map<std::string,std::shared_ptr<ITerrainModel>> _models;
};

#endif /* FIELDBUILDER_HPP */

