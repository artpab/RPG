/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.A
 */

/* 
 * File:   GameController.cpp
 * Author: goti
 * 
 * Created on January 6, 2019, 7:29 PM
 */

#include "GameController.hpp"

//GameController* GameController::_instance = nullptr;
GameController &GameController::getInstance()
{
    static GameController _instance;
    return _instance;
}

GameController::~GameController() {
}

void GameController::prepareMap()
{
    auto map_ptr = std::make_unique<Map>();
    std::vector<int> landscape_chance_vec {60,30,10};
  
    map_ptr->create_map(landscape_chance_vec);
}

void GameController::startGame(){
    
}