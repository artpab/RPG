/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Forest.hpp
 * Author: goti
 *
 * Created on January 6, 2019, 3:37 PM
 */

#ifndef FOREST_HPP
#define FOREST_HPP
#include "Field.hpp"

class Forest : public Field {
public:
//    Water();
    Forest(int X, int Y);
    virtual ~Forest();
    void printField() override;
    std::ostream& operator<< (std::ostream& stream) override;
private:
};

#endif /* FOREST_HPP */

