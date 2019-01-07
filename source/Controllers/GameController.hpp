/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameController.hpp
 * Author: goti
 *
 * Created on January 6, 2019, 7:29 PM
 */

#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
#include "MapController.hpp"
#include <memory>


class GameController {
public:
    static GameController& getInstance();
    GameController(GameController const&) = delete;
    void operator=(GameController const&) = delete;
    void prepareMap();
    void startGame();
    ~GameController();
private:
    GameController(){}

    std::unique_ptr<Map> gameMap;

};

#endif /* GAMECONTROLLER_HPP */

