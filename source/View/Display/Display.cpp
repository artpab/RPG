/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Display.cpp
 * Author: goti
 *
 * Created on January 13, 2019, 4:01 PM
 */

#include "Display.hpp"

Display::Display() {}

Display::Display(const Display &orig) {}

Display::~Display() {}

void Display::displayInfo(const std::pair<int, int> &field,
                          const worldVector &worldMap) {
  std::cout << "Selected Field info: \n";
  displayFieldInfo(field, worldMap);
  if (worldMap[field.first][field.second]->monsterAvailable()) {
    displayMonsterInfo(field, worldMap);
  } else {
    std::cout << "There is no monster on the field \n";
  }
}

void Display::displayFieldInfo(const std::pair<int, int> &field,
                               const worldVector &worldMap) {
  std::cout << "Terrain Type: "
            << worldMap[field.first][field.second]->getType() << "\n";
}

void Display::displayMonsterInfo(const std::pair<int, int> &field,
                                 const worldVector &worldMap) {
  auto monster_ptr = worldMap[field.first][field.second]->getMonsterPtr();
  std::cout << "Monster on the field: " << monster_ptr->getBreedPtr()->getName()
            << " HP: " << monster_ptr->getCurrentHealth() << "\n";
}
