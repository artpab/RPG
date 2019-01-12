/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WaterModel.hpp
 * Author: goti
 *
 * Created on January 12, 2019, 9:24 PM
 */

#ifndef WATERMODEL_HPP
#define WATERMODEL_HPP

#include "ITerrainModel.hpp"


class WaterModel : public ITerrainModel{
public:
    WaterModel();
    WaterModel(const WaterModel& orig);
    virtual ~WaterModel();
    long getMovementCost() override;
    bool isPassable() override;


private:
    long _movementCost = 5;
    bool _passable = false;
};

#endif /* WATERMODEL_HPP */

