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
#include "IField.hpp"
#include "TerrainModels/PlainsModel.hpp"

class Plains : public IField {
private:
    int _posX, _posY;
    std::shared_ptr<ITerrainModel> _model_ptr;
public:
    virtual ~Plains();
    Plains(int X, int Y, std::shared_ptr<ITerrainModel> ptr);
    std::string getType() override;
    int getX() override {return _posX;}
    int getY() override {return _posY;}
    std::string printField() override {return "."; }
    auto getModelptr() {return _model_ptr;}

private:

};

#endif /* PLAINS_HPP */

