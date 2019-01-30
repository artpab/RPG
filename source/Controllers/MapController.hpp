#ifndef MAPCONTROLLER_HPP
#define MAPCONTROLLER_HPP
#include "../Fields/Forest.hpp"
#include "../Fields/IField.hpp"
#include "../Fields/Plains.hpp"
#include "../Fields/TerrainModels/ITerrainModel.hpp"
#include "../Fields/Water.hpp"
#include "../MapIO/MapReader.hpp"
#include "../MapIO/MapWriter.hpp"
#include "../Monsters/MonsterGenerator.hpp"
#include "../View/Display/Display.hpp"
#include "Builders/FieldBuilder.hpp"
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

enum class FieldTypes { fields_chance, woods_chance, water_chance };

typedef std::vector<std::vector<std::shared_ptr<IField>>> worldVector;
typedef std::shared_ptr<worldVector> worldVector_ptr;
class MapController {
public:
  MapController();
  MapController(std::vector<int> chance_vec);
  virtual ~MapController();
  void create_map(const std::pair<int, int> &);
  void save_map();
  void load_map();
  void print_map();
  void displayFieldInfo(std::pair<int, int>);
  int getSizeX() { return _rows; };
  int getSizeY() { return _columns; };
  void initializeMap(worldVector &);
  void initializeMap();
  void populate();
  worldVector_ptr getMap();

private:
  worldVector _worldMap;
  std::vector<int> _chance_vec;
  std::shared_ptr<MapWriter> _pMapWriter;
  std::shared_ptr<MapReader> _pMapReader;
  std::shared_ptr<FieldBuilder> _pBuilder;
  std::shared_ptr<Display> _pDisplay;
  std::shared_ptr<MonsterGenerator> _pMGenerator;
  int _rows, _columns;
};

#endif /* MAPCONTROLLER_HPP */
