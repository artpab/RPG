/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plains.cpp
 * Author: goti
 * 
 * Created on January 6, 2019, 12:44 PM
 */

#include "Plains.hpp"

Plains::Plains(int X, int Y):Field(X,Y){}


Plains::~Plains() {
}

void Plains::printField()
{
    std::cout<<".";
}

std::ostream& Plains::operator<<(std::ostream& stream) {
    stream<<".";
}
