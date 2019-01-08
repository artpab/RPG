/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Water.hpp
 * Author: goti
 *
 * Created on January 6, 2019, 3:36 PM
 */

#ifndef WATER_HPP
#define WATER_HPP
#include "Field.hpp"

class Water : public Field {
public:
    Water(int X, int Y);
    Water(const Water& orig);
    virtual ~Water();
    void printField() override;
    std::string getType() override;
    std::ostream& operator<< (std::ostream& stream) override;
private:

};

#endif /* WATER_HPP */

