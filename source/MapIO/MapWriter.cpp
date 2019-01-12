/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapWriter.cpp
 * Author: goti
 * 
 * Created on January 7, 2019, 2:35 PM
 */

#include "MapWriter.hpp"

using boost::property_tree::ptree;
using boost::property_tree::write_xml;
using boost::property_tree::xml_writer_settings;

MapWriter::MapWriter() {
}


MapWriter::~MapWriter() {
}

void MapWriter::writeMap(const std::map<int, std::shared_ptr<IField>>&map_ptr) {

    ptree tree;

    tree.add("fields.<xmlattr>.version", "1.0");
    for (auto& elem : map_ptr) {
        ptree& field = tree.add("fields.field", "");
        field.add("id", elem.first);
        field.add("positionX", elem.second->getX());
        field.add("positionY", elem.second->getY());
        field.add("type", elem.second->getType());
    }
    std::string path_base {"/home/goti/Documents/C++Projects/RPG/"};
    std::string file_name;
    std::cout << "What is the name of the file? \n";    
    std::cin>>file_name;
    
    
    write_xml(path_base+file_name, tree,
            std::locale(),
            xml_writer_settings<std::string>(' ', 4));

}

