/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ITerrainModel.hpp
 * Author: goti
 *
 * Created on January 12, 2019, 9:24 PM
 */

#ifndef ITERRAINMODEL_HPP
#define ITERRAINMODEL_HPP

class ITerrainModel {
public:
    ITerrainModel();
    ITerrainModel(const ITerrainModel& orig);
    virtual ~ITerrainModel();
    long virtual getMovementCost() = 0;
    bool virtual isPassable() = 0;
    
private:

};

#endif /* ITERRAINMODEL_HPP */

