/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ForestModel.hpp
 * Author: goti
 *
 * Created on January 12, 2019, 9:23 PM
 */

#ifndef FORESTMODEL_HPP
#define FORESTMODEL_HPP

#include "ITerrainModel.hpp"


class ForestModel : public ITerrainModel{
public:
    ForestModel();
    ForestModel(const ForestModel& orig);
    virtual ~ForestModel();
    long getMovementCost() override;
    bool isPassable() override;


private:
    long _movementCost = 1;
    bool _passable = true;
};

#endif /* FORESTMODEL_HPP */

