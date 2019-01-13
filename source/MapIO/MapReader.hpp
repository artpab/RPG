/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapReader.hpp
 * Author: goti
 *
 * Created on January 8, 2019, 11:44 AM
 */

#ifndef MAPREADER_HPP
#define MAPREADER_HPP

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <map>
#include "../Fields/IField.hpp"
#include "../Fields/Forest.hpp"
#include "../Fields/Water.hpp"
#include "../Fields/Plains.hpp"
#include "../Controllers/Builders/FieldBuilder.hpp"
#include <iostream>
#include <boost/foreach.hpp>
#include <memory>

class MapReader {
public:
    MapReader(const std::shared_ptr<FieldBuilder>&);
    MapReader(const MapReader& orig);
    virtual ~MapReader();
    void loadMapfromXML(std::map<int,std::shared_ptr<IField>>&);

private:
    std::shared_ptr<FieldBuilder> _pBuilder;
};

#endif /* MAPREADER_HPP */

