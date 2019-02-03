
#include "MapController.hpp"
#include "memory"

MapController::MapController() : _chance_vec{0.1, 0.75, 0.15} {
  _pBuilder = std::make_shared<FieldBuilder>();
  _pDisplay = std::make_shared<Display>();
  _pMGenerator = std::make_shared<MonsterGenerator>();
}

MapController::MapController(std::vector<double> chance_vec)
    : _chance_vec(chance_vec) {
  _pBuilder = std::make_shared<FieldBuilder>();
  _pDisplay = std::make_shared<Display>();
}

MapController::~MapController() {}

void MapController::create_map(const std::pair<int, int> &dimensions) {
  srand(time(NULL));
  unsigned int seed = rand() % 256;
  PerlinNoise pn(seed);
  //  PerlinNoise pn;
  _rows = dimensions.first;
  _columns = dimensions.second;
  for (int i = 0; i < _rows; ++i) {
    std::vector<std::shared_ptr<IField>> vec;
    for (int j = 0; j < _columns; ++j) {
      double x = double(i) / double(_rows);
      double y = double(j) / double(_columns);
      double val = pn.noise(10 * x, 10 * y, 0.8);
      biomeSelector(vec, val, std::make_pair(i, j));
    }
    _worldMap.push_back(vec);
  }
}

void MapController::biomeSelector(std::vector<std::shared_ptr<IField>> &vec,
                                  double val, std::pair<int, int> pos) {
  if (val <= 0.4) {
    auto field_ptr = _pBuilder->createWater(pos.first, pos.second);
    vec.push_back(field_ptr);
  } else if (val <= 0.7) {
    auto field_ptr = _pBuilder->createPlains(pos.first, pos.second);
    vec.push_back(field_ptr);
  } else {
    auto field_ptr = _pBuilder->createForest(pos.first, pos.second);
    vec.push_back(field_ptr);
  }
}

void MapController::save_map() {
  _pMapWriter = std::make_shared<MapWriter>();
  _pMapWriter->writeMap(_worldMap, std::make_pair(_rows, _columns));
}

void MapController::load_map() {
  _pMapReader = std::make_shared<MapReader>(_pBuilder);
  _pMapReader->loadMapfromXML(_worldMap);
}

void MapController::print_map() {
  for (auto &element : _worldMap) {
    for (auto field : element) {
      std::cout << field->printField();
    }
    std::cout << "\n";
  }
}

void MapController::displayFieldInfo(std::pair<int, int> field) {
  _pDisplay->displayInfo(field, _worldMap);
}

void MapController::initializeMap(worldVector &_worldMap) {
  std::vector<std::shared_ptr<IField>> vec1(_columns, nullptr);
  worldVector vec2(_rows, vec1);
  _worldMap = vec2;
}

void MapController::initializeMap() { initializeMap(_worldMap); }

void MapController::populate() { _pMGenerator->populateMap(_worldMap); }
