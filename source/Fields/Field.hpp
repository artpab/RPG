/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Field.hpp
 * Author: goti
 *
 * Created on January 6, 2019, 12:12 PM
 */

#ifndef FIELD_HPP
#define FIELD_HPP

#include <cstdint>
#include <vector>
#include <iostream>

// Preferably polimorphism mechanism will be used.



class Field {
private:
    int posX, posY;
    bool visited{false};
public:
    Field() = delete;
    Field(const Field& orig) = delete;
    Field(int X, int Y);
    virtual ~Field();

    int getX(){return posX;} 
    int getY(){return posY;}
    virtual void printField() = 0;
    virtual std::ostream& operator<< (std::ostream& stream) = 0 ;
private:

};

#endif /* FIELD_HPP */

