/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WaterModel.cpp
 * Author: goti
 * 
 * Created on January 12, 2019, 9:24 PM
 */

#include "WaterModel.hpp"

WaterModel::WaterModel() {
}

WaterModel::WaterModel(const WaterModel& orig) {
}

WaterModel::~WaterModel() {
}

long WaterModel::getMovementCost() {
    return _movementCost;
}

bool WaterModel::isPassable() {

    return _passable;
}


