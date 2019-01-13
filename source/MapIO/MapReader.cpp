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

//using boost::property_tree::ptree;
//using boost::property_tree::write_xml;
//using boost::property_tree::xml_writer_settings;

MapReader::MapReader(const std::shared_ptr<FieldBuilder>& ptr):_pBuilder(ptr) {
}

MapReader::MapReader(const MapReader& orig) {
}

MapReader::~MapReader() {
}

void MapReader::loadMapfromXML(std::pair<int,int> dimensions, std::map<int, std::shared_ptr<IField>>&outputMap) {
    std::string file_name;
    std::string path_base{"/home/goti/Documents/C++Projects/RPG/"};
    std::cout << "What is the name of the file to load? \n";
    std::cin>>file_name;

    int id;

    // populate tree structure pt
    using boost::property_tree::ptree;
    ptree pt;
    read_xml(path_base + file_name, pt);

    // traverse pt

    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("fields")) {
        if (v.first == "field") {
            id = v.second.get<int>("id");
            if (v.second.get<std::string>("type") == "Plains") {
                
                
                auto field_ptr = _pBuilder->createPlains(v.second.get<int>("positionX"), v.second.get<int>("positionY"));
                outputMap.emplace(id, field_ptr);
            } else if (v.second.get<std::string>("type") == "Forest") {
                auto field_ptr = _pBuilder->createForest(v.second.get<int>("positionX"), v.second.get<int>("positionY"));
                outputMap.emplace(id, field_ptr);
            } else {
                auto field_ptr = _pBuilder->createWater(v.second.get<int>("positionX"), v.second.get<int>("positionY"));
                outputMap.emplace(id, field_ptr);
            }
        }
    }

}
