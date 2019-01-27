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

enum class GameStartingPoint { generate_new_map = 1, load_map_from_file = 2 };

class GameController {
public:
  static GameController &getInstance();
  GameController(GameController const &) = delete;
  void operator=(GameController const &) = delete;
  void prepareMap();
  void startGame();
  void gatherInformation();
  void setStartingPoint(const std::string &);
  std::pair<int, int> askForDimensions();
  void askForMapSave();
  void populateMap();
  ~GameController();

private:
  GameController();
  std::unique_ptr<MapController> ptr_MapController;
  GameStartingPoint startingPoint;
};

#endif /* GAMECONTROLLER_HPP */
