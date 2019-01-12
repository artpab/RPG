/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlainsModel.hpp
 * Author: goti
 *
 * Created on January 12, 2019, 9:23 PM
 */

#ifndef PLAINSMODEL_HPP
#define PLAINSMODEL_HPP
#include "ITerrainModel.hpp"

class PlainsModel : public ITerrainModel {
public:
    PlainsModel();
    PlainsModel(const PlainsModel& orig);
    virtual ~PlainsModel();
    long getMovementCost() override;
    bool isPassable() override;


private:
    long _movementCost = 1;
    bool _passable = true;

};

#endif /* PLAINSMODEL_HPP */

