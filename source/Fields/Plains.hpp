/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plains.hpp
 * Author: goti
 *
 * Created on January 6, 2019, 12:44 PM
 */

#ifndef PLAINS_HPP
#define PLAINS_HPP
#include "Field.hpp"

class Plains : public Field {
public:
    virtual ~Plains();
    Plains(int X, int Y);
    void printField() override;
    std::ostream& operator<< (std::ostream& stream) override;
private:

};

#endif /* PLAINS_HPP */

