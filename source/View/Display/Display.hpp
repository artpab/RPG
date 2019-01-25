/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Display.hpp
 * Author: goti
 *
 * Created on January 13, 2019, 4:01 PM
 */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <iostream>
//#include <pair>
#include <vector>
#include "../../Fields/IField.hpp"

typedef std::vector<std::vector<std::shared_ptr<IField>>> worldVector;

class Display {
public:
    Display();
    Display(const Display& orig);
    virtual ~Display();
    void displayInfo(const std::pair<int,int>&, const worldVector& worldMap);
private:

};

#endif /* DISPLAY_HPP */
