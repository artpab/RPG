/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: goti
 *
 * Created on January 6, 2019, 12:04 PM
 */

#include "source/Controllers/GameController.hpp"
#include <cstdlib>
#include <curses.h>
#include <iostream>
#include <memory>

/*
 *
 */
int main(int argc, char **argv) {

  GameController::getInstance().prepareMap();
  GameController::getInstance().startGame();
}
