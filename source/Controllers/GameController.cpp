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
#include <iostream>
#include <stdio.h>

GameController &GameController::getInstance() {
  static GameController _instance;
  return _instance;
}

GameController::~GameController() {}

GameController::GameController() {
  ptr_MapController = std::make_unique<MapController>();
  ptr_MFactory = std::make_unique<IMonsterFactory>();
}

void GameController::prepareMap() {
  gatherInformation();
  switch (startingPoint) {
  case GameStartingPoint::generate_new_map: {
    std::cout << " Generating a new map! \n";
    auto dimensions = askForDimensions();
    ptr_MapController->create_map(dimensions);
    ptr_MapController->print_map();
    askForMapSave();
    break;
  }
  case GameStartingPoint::load_map_from_file: {
    std::cout << "Loading map from a file! \n";
    //            ptr_MapController->initializeMap();
    ptr_MapController->load_map();
    ptr_MapController->print_map();
    break;
  }
  default: { break; }
  }
}

void GameController::startGame() {
  //    int c = 0;

  std::cout << "Would you like to get info about some field ?\n";
  auto position = askForDimensions();
  ptr_MapController->displayFieldInfo(position);
  populateMap();
}

void GameController::gatherInformation() {
  std::string input;
  std::cout << "Welcome to my primitive game !\n";
  std::cout << "Would you like to: \n 1)Generate a new map \n 2)Extract one "
               "from the file?";
  std::getline(std::cin, input);
  setStartingPoint(input);
}

void GameController::setStartingPoint(const std::string &choice) {
  startingPoint = (GameStartingPoint)std::stoi(choice);
}

std::pair<int, int> GameController::askForDimensions() {
  u_int32_t x = 0, y = 0;

  std::cout << "Please provide the dimensions for the map: \n";
  std::cout << "Number of rows: ";
  std::cin >> x;
  while (std::cin.fail()) {
    std::cout << "Please provide a proper value !\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> x;
  }
  std::cout << "Number of columns:  ";
  std::cin >> y;
  while (std::cin.fail()) {
    std::cout << "Please provide a proper value \n!";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> y;
  }
  return std::make_pair(x, y);
}

void GameController::askForMapSave() {
  std::string input;

  std::cout << "Would you like to save the map to file? (Y or N)\n";
  std::cin >> input;
  while (input != "Y" && input != "y" && input != "n" && input != "N") {
    std::cout << "Please provide a proper answer : yYNn !\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> input;
  }

  if (input == "Y" || input == "y") {
    ptr_MapController->save_map();
  }
}

void GameController::populateMap() { ptr_MapController->createMonsters(); }
