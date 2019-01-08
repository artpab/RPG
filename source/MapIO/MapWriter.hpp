/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapWriter.hpp
 * Author: goti
 *
 * Created on January 7, 2019, 2:35 PM
 */

#ifndef MAPWRITER_HPP
#define MAPWRITER_HPP
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <map>
#include "../Fields/Field.hpp"

class MapWriter {
public:
    MapWriter();
    virtual ~MapWriter();
    void writeMap(const std::map<int, std::shared_ptr<Field>>&);
private:

};

#endif /* MAPWRITER_HPP */

