/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Forest.cpp
 * Author: goti
 * 
 * Created on January 6, 2019, 3:37 PM
 */

#include "Forest.hpp"

Forest::Forest(int X, int Y) : Field(X, Y) {
}

void Forest::printField() {
    std::cout << "#";
}

Forest::~Forest() {
}

std::ostream& Forest::operator<<(std::ostream& stream) {
    stream << "#";
    return stream;
}
