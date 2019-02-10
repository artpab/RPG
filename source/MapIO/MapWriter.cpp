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

MapWriter::MapWriter() {}

MapWriter::~MapWriter() {}

void MapWriter::writeMap(const worldVector &map_ptr,
                         std::pair<int, int> dimensions) {

  ptree tree;
  ptree &data = tree.add("mapInfo", "");
  data.add("sizeX", dimensions.first);
  data.add("sizeY", dimensions.second);
  tree.add("fields.<xmlattr>.version", "1.0");
  for (auto &elemX : map_ptr)
    for (auto &elem : elemX) {
      ptree &field = tree.add("fields.field", "");
      field.add("positionX", elem->getX());
      field.add("positionY", elem->getY());
      field.add("type", elem->getType());
    }

  std::string path_base{"/home/goti/Documents/RPG/"};
  std::string file_name;
  std::cout << "What is the name of the file? \n";
  std::cin >> file_name;

  write_xml(path_base + file_name, tree, std::locale(),
            xml_writer_settings<std::string>(' ', 4));
}
