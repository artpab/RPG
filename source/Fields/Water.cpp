/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Water.cpp
 * Author: goti
 * 
 * Created on January 6, 2019, 3:36 PM
 */

#include "Water.hpp"

Water::Water(int X, int Y, std::shared_ptr<ITerrainModel> ptr) :_posX(X),_posY(Y), _model_ptr(ptr){
}

void Water::printField() {
    std::cout << "~";
}

Water::~Water() {
}

std::ostream& Water::operator<<(std::ostream& stream) {
    stream << "~";
    return stream;
}

std::string Water::getType()
{
    return "Water";
}