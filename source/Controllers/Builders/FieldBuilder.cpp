/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FieldBuilder.cpp
 * Author: goti
 * 
 * Created on January 13, 2019, 1:54 PM
 */

#include "FieldBuilder.hpp"

FieldBuilder::FieldBuilder() {
}

FieldBuilder::FieldBuilder(const FieldBuilder& orig) {
}

FieldBuilder::~FieldBuilder() {
    
}

void FieldBuilder::create_models() {
    _models.emplace("Plains", std::make_shared<PlainsModel>());
    _models.emplace("Water", std::make_shared<WaterModel>());
    _models.emplace("Forest", std::make_shared<ForestModel>());
}

std::shared_ptr<Plains> FieldBuilder::createPlains(int x,int y){
    return std::make_shared<Plains>(x,y,_models["Plains"]);
}
std::shared_ptr<Water> FieldBuilder::createWater(int x ,int y){
    return std::make_shared<Water>(x,y,_models["Water"]);
}
std::shared_ptr<Forest> FieldBuilder::createForest(int x,int y){
    return std::make_shared<Forest>(x,y,_models["Forest"]);
}