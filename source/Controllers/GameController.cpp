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

GameController &GameController::getInstance() {
    static GameController _instance;
    return _instance;
}

GameController::~GameController() {
}

void GameController::prepareMap() {
    gatherInformation();
    switch (startingPoint) {
        case GameStartingPoint::generate_new_map:
        {
            std::cout << " Generating a new map! \n";
            auto dimensions = askForDimensions();
            auto map_ptr = std::make_unique<Map>();
            std::vector<int> landscape_chance_vec{60, 30, 10};
            map_ptr->create_map(dimensions, landscape_chance_vec);
            break;
        }
        case GameStartingPoint::load_map_from_file:
        {
            std::cout << "Loading map from a file! \n";
            std::cout << "Not yet implemented! \n";
            break;
        }
        default:
        {
            break;
        }
    }

}

void GameController::startGame() {

}

void GameController::gatherInformation() {
    std::string input;
    std::cout << "Welcome to my primitive game !\n";
    std::cout << "Would you like to: \n 1)Generate a new map \n 2)Extract one from the file?";
    std::getline(std::cin, input);
    setStartingPoint(input);
}

void GameController::setStartingPoint(const std::string& choice) {
    startingPoint = (GameStartingPoint) std::stoi(choice);
}

std::pair<int, int> GameController::askForDimensions() {
    u_int32_t x=0, y=0;
   
    std::cout << "Please provide the dimensions for the map: \n";
    std::cout << "X: ";
    std::cin>>x;
    while (std::cin.fail())
    {
        std::cout << "Please provide a proper value !" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> x;
    }
    std::cout << "Y ";
    std::cin>>y;
    while (std::cin.fail())
    {
        std::cout << "Please provide a proper value !" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> y;
    }
    return std::make_pair(x, y);
}