/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapReader.cpp
 * Author: goti
 * 
 * Created on January 8, 2019, 11:44 AM
 */

#include "MapReader.hpp"


MapReader::MapReader(const std::shared_ptr<FieldBuilder>& ptr) : _pBuilder(ptr) {
}

MapReader::MapReader(const MapReader& orig) {
}

MapReader::~MapReader() {
}

void MapReader::loadMapfromXML(worldVector& world_map) {
    std::string file_name;
    std::string path_base{"/home/goti/Documents/C++Projects/RPG/"};
    std::cout << "What is the name of the file to load? \n";
    std::cin>>file_name;

    // populate tree structure pt
    using boost::property_tree::ptree;
    ptree pt;
    read_xml(path_base + file_name, pt);
    int sizeX;
    int sizeY;
    sizeX = pt.get<int>("mapInfo.sizeX");
    sizeY = pt.get<int>("mapInfo.sizeY");

    // traverse pt
    std::vector<std::shared_ptr < IField>> vec;
    int temp = 0;
    std::shared_ptr<IField> field_ptr;

    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("fields")) {
        int x, y;
        if (v.first == "field") {
            x = v.second.get<int>("positionX");
            y = v.second.get<int>("positionY");
            if (v.second.get<std::string>("type") == "Plains") {
                field_ptr = _pBuilder->createPlains(x, y);
            } else if (v.second.get<std::string>("type") == "Forest") {
                field_ptr = _pBuilder->createForest(x, y);
            } else {
                field_ptr = _pBuilder->createWater(x, y);
            }
            vec.push_back(field_ptr);
            ++temp;
            if (temp == sizeY) {
                temp = 0;
                world_map.push_back(vec);
                vec.clear();
            }


        }

    }
}
