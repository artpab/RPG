/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Display.cpp
 * Author: goti
 * 
 * Created on January 13, 2019, 4:01 PM
 */

#include "Display.hpp"

Display::Display() {
}

Display::Display(const Display& orig) {
}

Display::~Display() {
}

void Display::displayInfo(const std::pair<int,int>& field, const std::map<int, std::shared_ptr<IField>>& map)
{
    std::cout<<"DUPA";
}