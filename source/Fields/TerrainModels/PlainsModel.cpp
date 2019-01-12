/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlainsModel.cpp
 * Author: goti
 * 
 * Created on January 12, 2019, 9:23 PM
 */

#include "PlainsModel.hpp"

PlainsModel::PlainsModel() {
}

PlainsModel::PlainsModel(const PlainsModel& orig) {
}

PlainsModel::~PlainsModel() {
}

long PlainsModel::getMovementCost() {
    return _movementCost;
}

bool PlainsModel::isPassable() {
    return _passable;
}
