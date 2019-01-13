/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ForestModel.cpp
 * Author: goti
 * 
 * Created on January 12, 2019, 9:23 PM
 */

#include "ForestModel.hpp"

ForestModel::ForestModel(){
}

ForestModel::ForestModel(const ForestModel& orig) {
}

ForestModel::~ForestModel() {
}

long ForestModel::getMovementCost() {

    return _movementCost;
}

bool ForestModel::isPassable() {
    return _passable;
}


